# Algorithm: Selection and BinaryTree 

## Brief description:
At the beginning, the program reads the number sequence in input.txt (arrangement method is as specified in the title), and there is a program that can output 10000 random numbers (hw2_rand.c), and write the result after Sort into output.txt.

## Selection: (hw3_selet.c)
At the beginning, the program reads the sequence of numbers in input.txt (the arrangement method is the same as the previous operation), and writes the result after Sort into output.txt. There are two main functions (selectionAlgorithm and medianOfMedians), roughly sorting forward (returning the index value in the specified sequence) and the rear function is finding the median (returning the index value of the "approximate median" of the sequence). The steps to find the median are roughly as follows: 
* Divide the 5 numbers in the sequence into one pile, and find the median for each group
* Use insertion sort to get the median
* After all the medians are obtained, call selectionAlgorithm to find the median of the medians

The subject is a given position in the sequence and then find its sorted value. This job is an algorithm that can be found in O(n) in the worst case, so as long as the pivot can be as long as possible, the efficiency can be At its worst, it reaches O(n).

## BinaryTree: (hw3_binary.c)
Inorder sorting (left->visit->right) is used here, and the functions are (insert, delete, minValue, maxValue, Search, findPredesuccesorAndSuccessor)
The task of deleting data is divided into three categories according to the deleted node "how many child pointers":
* The deleted node has no child pointer
* The deleted node has only one child pointer (whether it is leftchild or rightchild)
* The deleted node has two child pointers

The Search operation is based on the characteristics of BST: Key(L)<Key(Current)<Key(R), to determine whether Current should go to the left subtree or the right subtree.

Insert is to find the "suitable position" of the node to be added according to the rules of BST for Key, and then connect the node to be added to the BST.
To find (the appropriate location for the newly added node), you need to define current first, and the node that will become the parent of the newly added node will move forward with x.

## Program environment:
Implement on C (Dev C++, GCC 4.9.2)








