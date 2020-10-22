#include<stdio.h> 
#include<string.h>
#include<stdlib.h> 
  
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// create a new BST node 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// inorder traversal
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 
  
// insert a new node with given key in BST 
struct node* insert(struct node* node, int key) 
{ 
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);   
    if (key < node->key) node->left  = insert(node->left, key); 
    else node->right = insert(node->right, key);  
    return node; 
} 
 
int minValue(struct node* node)  
{  
	struct node* current = node;  
	// loop down to find the leftmost leaf 
	while (current->left != NULL)  
	{	  
    	current = current->left;  
	}	  
	return(current->key);  
}  

int maxValue(struct node* node)  
{  
	struct node* current = node;  
	while (current->right != NULL)  
	{	  
    	current = current->right;  
	}	  
	return(current->key);  
}
 

struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->left != NULL) 
        current = current->left;   
    return current; 
} 
/*   
struct node * maxValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current->right != NULL) 
        current = current->right; 
    return current; 
} 
*/  

struct node* search(struct node* root, int key) 
{ 
    // root is null or key is present at root 
    if (root == NULL || root->key == key) return root;     
    if (root->key < key) return search(root->right, key); 
    return search(root->left, key); 
} 
  
void findPreSuc(struct node* root, struct node* pre, struct node* suc, int key) 
{ 
    if (root == NULL) return; 
    // Search for given key in BST. 
    while (root != NULL) 
	{  
        // If root is given key. 
        if (root->key == key) 
		{  
            // the minimum value in right subtree is predecessor.
            if (root->right) 
			{ 
                suc = root->right; 
                while (suc->left) suc = suc->left; 
            } 
            // the maximum value in left subtree is successor 
            if (root->left) 
			{ 
                pre = root->left; 
                while (pre->right) pre = pre->right; 
            } 
            return; 
        } 
        else if (root->key < key) 
		{ 
            pre = root; 
            root = root->right; 
        } 
        else 
		{ 
            suc = root; 
            root = root->left; 
        } 
    } 
} 

// deletes the key and returns the new root
struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root;  
    // If the key to be deleted is smaller than the root's key -> left subtree 
    if (key < root->key) root->left = deleteNode(root->left, key);  
    // If the key to be deleted is greater than the root's key -> right subtree 
    else if (key > root->key) root->right = deleteNode(root->right, key); 
    // if key is same as root's key, then This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        }  
        // node with two children: Get the inorder successor (smallest in the right subtree) 
        struct node* temp = minValueNode(root->right);  
        root->key = temp->key; 
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
  
int main() 
{ 
	int key = 65; 
    struct node *root = NULL; 
    printf("Inorder traversal of insert 50 30 20 40 70 60 80\n");
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
  
    printf("Inorder traversal:\n"); 
    inorder(root);  
    printf("\nDelete 20\n"); 
    root = deleteNode(root, 20); 
    printf("Inorder traversal:\n"); 
    inorder(root);  
    printf("\nDelete 30\n"); 
    root = deleteNode(root, 30); 
    printf("Inorder traversal:\n"); 
    inorder(root);   
    printf("\nDelete 50\n"); 
    root = deleteNode(root, 50); 
    printf("Inorder traversal:\n"); 
    inorder(root);  
    
	printf("\nMaximum element is %d \n", maxValue(root));
	printf("Minimum element is %d \n", minValue(root));
	
	struct node *pre = NULL;
	struct node *suc = NULL; 	
    findPreSuc(root, pre, suc, key); 
    if (pre != NULL) printf("Predecessor is %d \n", pre->key);
    else printf("Predecessor is NULL\n");
    if (suc != NULL) printf("Successor is %d \n", suc->key);
    else printf("Successor is NULL\n"); 
    return 0; 
} 
