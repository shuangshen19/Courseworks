/*
  Red Black Trees
  (C) 1999  Andrea Arcangeli <andrea@suse.de>
  (C) 2002  David Woodhouse <dwmw2@infradead.org>
  (C) 2012  Michel Lespinasse <walken@google.com>
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  linux/lib/rbtree.c
*/

#include <linux/rbtree_augmented.h>
#include <linux/export.h>

/*
 * red-black trees properties:  http://en.wikipedia.org/wiki/Rbtree
 *
 *  1) A node is either red or black
 *  2) The root is black
 *  3) All leaves (NULL) are black
 *  4) Both children of every red node are black
 *  5) Every simple path from root to leaves contains the same number
 *     of black nodes.
 *
 *  4 and 5 give the O(log n) guarantee, since 4 implies you cannot have two
 *  consecutive red nodes in a path and every red node is therefore followed by
 *  a black. So if B is the number of black nodes on every simple path (as per
 *  5), then the longest possible path due to 4 is 2B.
 *
 *  We shall indicate color with case, where black nodes are uppercase and red
 *  nodes will be lowercase. Unknown color nodes shall be drawn as red within
 *  parentheses and have some accompanying text comment.
 */

/*
 * Notes on lockless lookups:
 *
 * All stores to the tree structure (rb_left and rb_right) must be done using
 * WRITE_ONCE(). And we must not inadvertently cause (temporary) loops in the
 * tree structure as seen in program order.
 *
 * These two requirements will allow lockless iteration of the tree -- not
 * correct iteration mind you, tree rotations are not atomic so a lookup might
 * miss entire subtrees.
 *
 * But they do guarantee that any such traversal will only see valid elements
 * and that it will indeed complete -- does not get stuck in a loop.
 *
 * It also guarantees that if the lookup returns an element it is the 'correct'
 * one. But not returning an element does _NOT_ mean it's not present.
 *
 * NOTE:
 *
 * Stores to __rb_parent_color are not important for simple lookups so those
 * are left undone as of now. Nor did I check for loops involving parent
 * pointers.
 */

static inline void rb_set_black(struct rb_node *rb)
{
	rb->__rb_parent_color |= RB_BLACK; // 把parent設為黑色 
}

static inline struct rb_node *rb_red_parent(struct rb_node *red)
{
	return (struct rb_node *)red->__rb_parent_color; // 回傳parent
}

/*
 * Helper function for rotations:
 * - old's parent and color get assigned to new
 * - old gets assigned new as a parent and 'color' as a color.
 */
static inline void // 更換新parent
__rb_rotate_set_parents(struct rb_node *old, struct rb_node *new,
			struct rb_root *root, int color)
{
	struct rb_node *parent = rb_parent(old); // 得到old parent，建造新parent
	new->__rb_parent_color = old->__rb_parent_color; // old assign new
	rb_set_parent_color(old, new, color); //old gets assigned new as a parent and 'color' as a color 
	__rb_change_child(old, new, parent, root); // change child to new
}

static __always_inline void
__rb_insert(struct rb_node *node, struct rb_root *root,
	    bool newleft, struct rb_node **leftmost,
	    void (*augment_rotate)(struct rb_node *old, struct rb_node *new))
{
	// 定義parent為node的父節點
	struct rb_node *parent = rb_red_parent(node), *gparent, *tmp;

	if (newleft)
		*leftmost = node;

	while (true) {
		/*
		 * Loop invariant: node is red. // 初始設定插入的節點為紅色
		 */
		 // node在樹根
		if (unlikely(!parent)) { // don't want a red root or two consecutive red nodes
			/*
			 * The inserted node is root. Either this is the
			 * first node, or we recursed at Case 1 below and
			 * are no longer violating 4).
			 */
			rb_set_parent_color(node, NULL, RB_BLACK); // node設為黑色
			break;
		}

		/*
		 * If there is a black parent, we are done.
		 * Otherwise, take some corrective action as,
		 * per 4), we don't want a red root or two
		 * consecutive red nodes.
		 */
		if(rb_is_black(parent))  // 如果新節點的parent為黑色
			break; // 符合條件(插入的節點為紅色不影響性質)

		gparent = rb_red_parent(parent); // 定義祖父節點

		// 經過上面，這裡parent一定是紅色節點8
		// gparent為黑色13
		tmp = gparent->rb_right; // tmp是gparent的右節點 
		if (parent != tmp) {	/* parent == gparent->rb_left */ // 成立，當parent是gparent的的左節點時(此時tmp為叔父節點(u)) 
			if (tmp && rb_is_red(tmp)) { // u exists and is red
				/*
				 * Case 1 - node's uncle is red (color flips).
				 *
				 *       G            g
				 *      / \          / \
				 *     p   u  -->   P   U
				 *    /            /
				 *   n            n
				 *
				 * However, since g's parent might be red, and
				 * 4) does not allow this, we need to recurse
				 * at g.
				 */
				rb_set_parent_color(tmp, gparent, RB_BLACK); // tmp(u) --> black
				rb_set_parent_color(parent, gparent, RB_BLACK); // parent --> black
				node = gparent; // 將gparent視為新節點 
				parent = rb_parent(node); // 將parent改為gparent的父節點
				rb_set_parent_color(node, parent, RB_RED); // gparent --> red
				continue; // 從頭開始，向上新一輪處理
			}
			
			// u doesn't exists or u's color is black
			tmp = parent->rb_right; // tmp是p的右節點
			if (node == tmp) { // node為p的右節點成立時
				/*
				 * Case 2 - node's uncle is black and node is
				 * the parent's right child (left rotate at parent).
				 *
				 *      G             G
				 *     / \           / \
				 *    p   U  -->    n   U
				 *     \           /
				 *      n         p
				 *
				 * This still leaves us in violation of 4), the
				 * continuation into Case 3 will fix that.
				 */
				tmp = node->rb_left; // tmp為node的左節點
				WRITE_ONCE(parent->rb_right, tmp); // p的右節點設為tmp
				WRITE_ONCE(node->rb_left, parent); // n的左節點設為p
				if (tmp) // tmp存在並設為黑色
					rb_set_parent_color(tmp, parent,
							    RB_BLACK);
				rb_set_parent_color(parent, node, RB_RED); // p --> red
				augment_rotate(parent, node); // 對p,n做左旋轉
				parent = node; // p視為新節點(p,n皆為紅色,不符合性質4 --> Case3)
				tmp = node->rb_right; // tmp設為p的右節點 
			}
			// node為p的左節點時 
			/*
			 * Case 3 - node's uncle is black and node is
			 * the parent's left child (right rotate at gparent).
			 *
			 *        G           P
			 *       / \         / \
			 *      p   U  -->  n   g
			 *     /                 \
			 *    n                   U
			 */
			// p的右節點設為g的左節點
			WRITE_ONCE(gparent->rb_left, tmp); /* == parent->rb_right */
			WRITE_ONCE(parent->rb_right, gparent); // g設為p的右節點 
			if (tmp) // tmp存在並設為黑色
				rb_set_parent_color(tmp, gparent, RB_BLACK);
			__rb_rotate_set_parents(gparent, parent, root, RB_RED); // g --> red
			augment_rotate(gparent, parent); // g,p做右旋轉
			break;
		} else { 
			// p是gparent的右節點時 
			tmp = gparent->rb_left; // tmp為u
			if (tmp && rb_is_red(tmp)) { // u is red
				/* Case 1 - color flips */
				rb_set_parent_color(tmp, gparent, RB_BLACK); // tmp --> black
				rb_set_parent_color(parent, gparent, RB_BLACK); // p --> black
				node = gparent; // gparent --> new node
				parent = rb_parent(node); // parent改為gparent的父節點 
				rb_set_parent_color(node, parent, RB_RED); //g --> red
				continue; // 從頭開始，向上新一輪處理
			}

			tmp = parent->rb_left; // tmp是parent的左節點 
			if (node == tmp) {
				// node是parent的左節點
				/* Case 2 - right rotate at parent */
				tmp = node->rb_right; // tmp設為n的右節點 
				WRITE_ONCE(parent->rb_left, tmp); // tmp設為p的左節點 
				WRITE_ONCE(node->rb_right, parent); // p設為n的右節點 
				if (tmp) // tmp存在並設為黑色
					rb_set_parent_color(tmp, parent,
							    RB_BLACK);
				rb_set_parent_color(parent, node, RB_RED); // p --> red
				augment_rotate(parent, node); // p,n做右旋轉
				parent = node; // p視為新節點(p,n皆為紅色,不符合性質4 --> Case3)
				tmp = node->rb_left; // tmp設為p的右節點 
			}

			/* Case 3 - left rotate at gparent */
			// node為p的右節點時 
			// p的左節點設為g的右節點
			WRITE_ONCE(gparent->rb_right, tmp); /* == parent->rb_left */
			WRITE_ONCE(parent->rb_left, gparent); // g設為p的左節點 
			if (tmp) // tmp存在並設為黑色
				rb_set_parent_color(tmp, gparent, RB_BLACK);
			__rb_rotate_set_parents(gparent, parent, root, RB_RED); // g --> red
			augment_rotate(gparent, parent); // g,p做左旋轉
			break;
		}
	}
}

/*
 * Inline version for rb_erase() use - we want to be able to inline
 * and eliminate the dummy_rotate callback there
 */
static __always_inline void
____rb_erase_color(struct rb_node *parent, struct rb_root *root,
	void (*augment_rotate)(struct rb_node *old, struct rb_node *new))
{
	struct rb_node *node = NULL, *sibling, *tmp1, *tmp2;

	while (true) {
		/*
		 * Loop invariants:
		 * - node is black (or NULL on first iteration)
		 * - node is not the root (parent is not NULL)
		 * - All leaf paths going through parent and node have a
		 *   black node count that is 1 lower than other leaf paths.
		 */
		sibling = parent->rb_right; // sibling是parent的右節點
		if (node != sibling) {	// n為p的左節點 /* node == parent->rb_left */
			if (rb_is_red(sibling)) { // s為紅色
				/*
				 * Case 1 - left rotate at parent
				 *
				 *     P               S
				 *    / \             / \
				 *   N   s    -->    p   Sr
				 *      / \         / \
				 *     Sl  Sr      N   Sl
				 */
				tmp1 = sibling->rb_left; // tmp1為s的左節點
				WRITE_ONCE(parent->rb_right, tmp1); // s設為p的右節點 
				WRITE_ONCE(sibling->rb_left, parent); // p設為s的左節點 --> s為祖父
				rb_set_parent_color(tmp1, parent, RB_BLACK); // s --> black
				__rb_rotate_set_parents(parent, sibling, root,
							RB_RED); // p --> red
				augment_rotate(parent, sibling); // p,s做左旋轉
				sibling = tmp1;
			}
			// s為黑色
			tmp1 = sibling->rb_right; // tmp1為s的右節點
			if (!tmp1 || rb_is_black(tmp1)) { // s的右節點不存在或為黑色
				tmp2 = sibling->rb_left; // tmp2為s的左節點
				if (!tmp2 || rb_is_black(tmp2)) { // s的左節點不存在或為黑色
					/*
					 * Case 2 - sibling color flip
					 * (p could be either color here)
					 *
					 *    (p)           (p)
					 *    / \           / \
					 *   N   S    -->  N   s
					 *      / \           / \
					 *     Sl  Sr        Sl  Sr
					 *
					 * This leaves us violating 5) which
					 * can be fixed by flipping p to black
					 * if it was red, or by recursing at p.
					 * p is red when coming from Case 1.
					 */
					rb_set_parent_color(sibling, parent,
							    RB_RED); // s --> red
					if (rb_is_red(parent)) // p --> red
						rb_set_black(parent); // p --> black
					else { // p is black
						node = parent; // p為新節點
						parent = rb_parent(node); // parent為新節點的父節點 
						if (parent) // parent存在,繼續做 
							continue;
					}
					break;
				}
				
				//當s的左節點為紅色
				/*
				 * Case 3 - right rotate at sibling
				 * (p could be either color here)
				 *
				 *   (p)           (p)
				 *   / \           / \
				 *  N   S    -->  N   sl
				 *     / \             \
				 *    sl  Sr            S
				 *                       \
				 *                        Sr
				 *
				 * Note: p might be red, and then both
				 * p and sl are red after rotation(which
				 * breaks property 4). This is fixed in
				 * Case 4 (in __rb_rotate_set_parents()
				 *         which set sl the color of p
				 *         and set p RB_BLACK)
				 *
				 *   (p)            (sl)
				 *   / \            /  \
				 *  N   sl   -->   P    S
				 *       \        /      \
				 *        S      N        Sr
				 *         \
				 *          Sr
				 */
				// 右旋轉
				// sl = s的左節點，sr = s的右節點  
				tmp1 = tmp2->rb_right; //tmp1是sl的右節點 
				WRITE_ONCE(sibling->rb_left, tmp1);  // tmp1設為s的左節點 
				WRITE_ONCE(tmp2->rb_right, sibling); // s設為sl的右節點 
				WRITE_ONCE(parent->rb_right, tmp2); // sl設為p的右節點
				if (tmp1)
					rb_set_parent_color(tmp1, sibling,
							    RB_BLACK); // tmp1 --> black
				augment_rotate(sibling, tmp2); // s,sl做右旋轉
				tmp1 = sibling;
				sibling = tmp2; // n的s變成sl 
			}
			/*
			 * Case 4 - left rotate at parent + color flips
			 * (p and sl could be either color here.
			 *  After rotation, p becomes black, s acquires
			 *  p's color, and sl keeps its color)
			 *
			 *      (p)             (s)
			 *      / \             / \
			 *     N   S     -->   P   Sr
			 *        / \         / \
			 *      (sl) sr      N  (sl)
			 */
			tmp2 = sibling->rb_left;
			WRITE_ONCE(parent->rb_right, tmp2); // sl設為p的右節點 
			WRITE_ONCE(sibling->rb_left, parent); // p設為s的左節點 
			rb_set_parent_color(tmp1, sibling, RB_BLACK); // sr --> black
			if (tmp2) // s1存在
				rb_set_parent(tmp2, parent); // p設為sl的父節點
			__rb_rotate_set_parents(parent, sibling, root,
						RB_BLACK); // p --> black
			augment_rotate(parent, sibling); // p,s做左旋轉 
			break;
		} else {
			// n為p的右節點
			sibling = parent->rb_left;
			if (rb_is_red(sibling)) { // s is red
				/* Case 1 - right rotate at parent */
				tmp1 = sibling->rb_right; // tmp1為sr 
				WRITE_ONCE(parent->rb_left, tmp1); // sr設為p的左節點 
				WRITE_ONCE(sibling->rb_right, parent); // p設為s的右節點
				rb_set_parent_color(tmp1, parent, RB_BLACK); // sr --> black
				__rb_rotate_set_parents(parent, sibling, root,
							RB_RED); // p --> red
				augment_rotate(parent, sibling); // p,s做右旋轉
				sibling = tmp1; // s設為sr
			}
			// s is black
			tmp1 = sibling->rb_left;
			if (!tmp1 || rb_is_black(tmp1)) {
				tmp2 = sibling->rb_right;
				if (!tmp2 || rb_is_black(tmp2)) {
					/* Case 2 - sibling color flip */
					rb_set_parent_color(sibling, parent,
							    RB_RED);
					if (rb_is_red(parent))
						rb_set_black(parent);
					else {
						node = parent; // p視為新節點 
						parent = rb_parent(node); // parent為新節點的父節點
						if (parent) // parent存在,繼續做 
							continue;
					}
					break;
				}
				/* Case 3 - left rotate at sibling */
				tmp1 = tmp2->rb_left;
				WRITE_ONCE(sibling->rb_right, tmp1);
				WRITE_ONCE(tmp2->rb_left, sibling);
				WRITE_ONCE(parent->rb_left, tmp2);
				if (tmp1)
					rb_set_parent_color(tmp1, sibling,
							    RB_BLACK); // tmp1 --> black
				augment_rotate(sibling, tmp2); // s,sr做左旋轉 
				tmp1 = sibling;
				sibling = tmp2; // n的s變成sr 
			}
			/* Case 4 - right rotate at parent + color flips */
			tmp2 = sibling->rb_right;
			WRITE_ONCE(parent->rb_left, tmp2);
			WRITE_ONCE(sibling->rb_right, parent);
			rb_set_parent_color(tmp1, sibling, RB_BLACK);
			if (tmp2) // sr存在 
				rb_set_parent(tmp2, parent); // p設為sr的父節點 
			__rb_rotate_set_parents(parent, sibling, root,
						RB_BLACK); // p --> black
			augment_rotate(parent, sibling); // p,s做右旋轉
			break;
		}
	}
}

/* Non-inline version for rb_erase_augmented() use */
void __rb_erase_color(struct rb_node *parent, struct rb_root *root,
	void (*augment_rotate)(struct rb_node *old, struct rb_node *new))
{
	____rb_erase_color(parent, root, augment_rotate);
}
EXPORT_SYMBOL(__rb_erase_color);

/*
 * Non-augmented rbtree manipulation functions.
 *
 * We use dummy augmented callbacks here, and have the compiler optimize them
 * out of the rb_insert_color() and rb_erase() function definitions.
 */

static inline void dummy_propagate(struct rb_node *node, struct rb_node *stop) {}
static inline void dummy_copy(struct rb_node *old, struct rb_node *new) {}
static inline void dummy_rotate(struct rb_node *old, struct rb_node *new) {}

static const struct rb_augment_callbacks dummy_callbacks = {
	.propagate = dummy_propagate,
	.copy = dummy_copy,
	.rotate = dummy_rotate
};

void rb_insert_color(struct rb_node *node, struct rb_root *root)
{
	__rb_insert(node, root, false, NULL, dummy_rotate);
}
EXPORT_SYMBOL(rb_insert_color);

void rb_erase(struct rb_node *node, struct rb_root *root)
{
	struct rb_node *rebalance;
	rebalance = __rb_erase_augmented(node, root,
					 NULL, &dummy_callbacks);
	if (rebalance)
		____rb_erase_color(rebalance, root, dummy_rotate);
}
EXPORT_SYMBOL(rb_erase);

void rb_insert_color_cached(struct rb_node *node,
			    struct rb_root_cached *root, bool leftmost)
{
	__rb_insert(node, &root->rb_root, leftmost,
		    &root->rb_leftmost, dummy_rotate);
}
EXPORT_SYMBOL(rb_insert_color_cached);

void rb_erase_cached(struct rb_node *node, struct rb_root_cached *root)
{
	struct rb_node *rebalance;
	rebalance = __rb_erase_augmented(node, &root->rb_root,
					 &root->rb_leftmost, &dummy_callbacks);
	if (rebalance)
		____rb_erase_color(rebalance, &root->rb_root, dummy_rotate);
}
EXPORT_SYMBOL(rb_erase_cached);

/*
 * Augmented rbtree manipulation functions.
 *
 * This instantiates the same __always_inline functions as in the non-augmented
 * case, but this time with user-defined callbacks.
 */

void __rb_insert_augmented(struct rb_node *node, struct rb_root *root,
			   bool newleft, struct rb_node **leftmost,
	void (*augment_rotate)(struct rb_node *old, struct rb_node *new))
{
	__rb_insert(node, root, newleft, leftmost, augment_rotate);
}
EXPORT_SYMBOL(__rb_insert_augmented);

/*
 * This function returns the first node (in sort order) of the tree.
 */
struct rb_node *rb_first(const struct rb_root *root)
{
	struct rb_node	*n;

	n = root->rb_node;
	if (!n)
		return NULL;
	while (n->rb_left)
		n = n->rb_left;
	return n;
}
EXPORT_SYMBOL(rb_first);

struct rb_node *rb_last(const struct rb_root *root)
{
	struct rb_node	*n;

	n = root->rb_node;
	if (!n)
		return NULL;
	while (n->rb_right)
		n = n->rb_right;
	return n;
}
EXPORT_SYMBOL(rb_last);

struct rb_node *rb_next(const struct rb_node *node)
{
	struct rb_node *parent;

	if (RB_EMPTY_NODE(node))
		return NULL;

	/*
	 * If we have a right-hand child, go down and then left as far
	 * as we can.
	 */
	if (node->rb_right) {
		node = node->rb_right;
		while (node->rb_left)
			node=node->rb_left;
		return (struct rb_node *)node;
	}

	/*
	 * No right-hand children. Everything down and left is smaller than us,
	 * so any 'next' node must be in the general direction of our parent.
	 * Go up the tree; any time the ancestor is a right-hand child of its
	 * parent, keep going up. First time it's a left-hand child of its
	 * parent, said parent is our 'next' node.
	 */
	while ((parent = rb_parent(node)) && node == parent->rb_right)
		node = parent;

	return parent;
}
EXPORT_SYMBOL(rb_next);

struct rb_node *rb_prev(const struct rb_node *node)
{
	struct rb_node *parent;

	if (RB_EMPTY_NODE(node))
		return NULL;

	/*
	 * If we have a left-hand child, go down and then right as far
	 * as we can.
	 */
	if (node->rb_left) {
		node = node->rb_left;
		while (node->rb_right)
			node=node->rb_right;
		return (struct rb_node *)node;
	}

	/*
	 * No left-hand children. Go up till we find an ancestor which
	 * is a right-hand child of its parent.
	 */
	while ((parent = rb_parent(node)) && node == parent->rb_left)
		node = parent;

	return parent;
}
EXPORT_SYMBOL(rb_prev);

void rb_replace_node(struct rb_node *victim, struct rb_node *new,
		     struct rb_root *root)
{
	struct rb_node *parent = rb_parent(victim);

	/* Copy the pointers/colour from the victim to the replacement */
	*new = *victim;

	/* Set the surrounding nodes to point to the replacement */
	if (victim->rb_left)
		rb_set_parent(victim->rb_left, new);
	if (victim->rb_right)
		rb_set_parent(victim->rb_right, new);
	__rb_change_child(victim, new, parent, root);
}
EXPORT_SYMBOL(rb_replace_node);

void rb_replace_node_cached(struct rb_node *victim, struct rb_node *new,
			    struct rb_root_cached *root)
{
	rb_replace_node(victim, new, &root->rb_root);

	if (root->rb_leftmost == victim)
		root->rb_leftmost = new;
}
EXPORT_SYMBOL(rb_replace_node_cached);

void rb_replace_node_rcu(struct rb_node *victim, struct rb_node *new,
			 struct rb_root *root)
{
	struct rb_node *parent = rb_parent(victim);

	/* Copy the pointers/colour from the victim to the replacement */
	*new = *victim;

	/* Set the surrounding nodes to point to the replacement */
	if (victim->rb_left)
		rb_set_parent(victim->rb_left, new);
	if (victim->rb_right)
		rb_set_parent(victim->rb_right, new);

	/* Set the parent's pointer to the new node last after an RCU barrier
	 * so that the pointers onwards are seen to be set correctly when doing
	 * an RCU walk over the tree.
	 */
	__rb_change_child_rcu(victim, new, parent, root);
}
EXPORT_SYMBOL(rb_replace_node_rcu);

static struct rb_node *rb_left_deepest_node(const struct rb_node *node)
{
	for (;;) {
		if (node->rb_left)
			node = node->rb_left;
		else if (node->rb_right)
			node = node->rb_right;
		else
			return (struct rb_node *)node;
	}
}

struct rb_node *rb_next_postorder(const struct rb_node *node)
{
	const struct rb_node *parent;
	if (!node)
		return NULL;
	parent = rb_parent(node);

	/* If we're sitting on node, we've already seen our children */
	if (parent && node == parent->rb_left && parent->rb_right) {
		/* If we are the parent's left node, go to the parent's right
		 * node then all the way down to the left */
		return rb_left_deepest_node(parent->rb_right);
	} else
		/* Otherwise we are the parent's right node, and the parent
		 * should be next */
		return (struct rb_node *)parent;
}
EXPORT_SYMBOL(rb_next_postorder);

struct rb_node *rb_first_postorder(const struct rb_root *root)
{
	if (!root->rb_node)
		return NULL;

	return rb_left_deepest_node(root->rb_node);
}
EXPORT_SYMBOL(rb_first_postorder);