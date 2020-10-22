# K-map

## Descriptions
In this homework, you will write a program to implement a (2 ~ 4-Variable) K Map
simplification process. The prime implicants and the essential prime implicants of
the K Map should be indicated, too. Finally, your program should show the
Minimum SOP (Sum of Product).

## Requirement
* Read the input file
Your program will read the input file for the minterm information and don’t care information:
eg. F(A, B, C,D) = ∑m(0,1,5,11,15) + ∑d(4,6,10,14)
The format of the information are followed by Input/OutputSpecification.
* Initialize the terms in the K Map, and do the simplification. You can create one or two-dimensional arrays to allocate all the terms of K Map. The order should follow the order in this assignment.
* Write the output file. When the program starts execution, print the initial contents of K-Map
at first. Also, you must print the prime implicants, the essential prime implicants and the boolean algebra to show the Minimum SOP.

## Input/Output Specification
Your program should read input file, and put these terms into K-map. After
program execution, output file should be created to dump the information for
the simplification results.
Input: input_m.txt, input_d.txt
Output: output.txt

## Operation Manual
* Put the two files (minterm and don’t care) and the code in the same folder first
* Then open run_cmd and compile java file to execute the code
* Enter minterm's txt file name and dontcare's txt file name in sequence according to the instructions given by the program (remember to add file name.txt, otherwise the file will not be found)
* The result will be displayed in the output.txt file

## Programming Process
* Read the file and store minterm and don’t care into a one-dimensional matrix (the number representing minterm is 1; don’t care is 2)
* Declare a two-dimensional matrix kmap, first set all to 0, and save minterm as 1 or don’t care as 2 according to the input file
* Pair minterm and don’t care with each other to find minterm and don’t care that can be paired in the same way
* Continue to pair until it can no longer be paired is the prime implicant we want
* Let another one-dimensional matrix count access the circled minterm. If count==1 at the end, it means that the circled prime implicant is an essential prime implicant
* The essential prime implicant must be one of the solutions of the minimum solution, and finally the minimum solution is selected for the remaining prime implicant, and then replaced with letters (ABCD)
* Finally, output the results according to the operation regulations

## Program environment:
Implement on JAVA

