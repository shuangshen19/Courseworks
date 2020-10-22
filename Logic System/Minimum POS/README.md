# Minimum POS

## Descriptions
This assignment is similar with assignment 1. In this homework, you will write
a program to implement a (2 ~ 4-Variable) K Map simplification process.
Finally, your program should show the Minimum POS (Product of Sum), with
the prevention of static 0 hazard.

## Requirement
* You don’t have to show prime implicants and essential prime implicants.
* The function F(A,B,C,D) changes to POS answer (ex. (a+c’)*(a’+c) )
and the answer should prevent the static 0 hazard.

## Operation Manual
* Put the two files (minterm and don’t care) and the code in the same folder first
* Then open run_cmd and compile java file to execute the code
* Enter the txt file name of minterm and the txt file of don’t care in sequence according to the instructions given by the program (Remember to add the file name .txt, otherwise the file will not be found)
* The result will be displayed in the output.txt file
* The Karnaugh map shows the same as before but F is changed to POS
  
## Programming process
* Read the file and store minterm and don’t care into a one-dimensional matrix (the number representing minterm is 1; don’t care is 2)
* Declare a two-dimensional matrix kmap, first set all to 0, and save the minterm according to the input file Save as 1 or don’t care as 2
* Pair minterm and don’t care with each other to find minterm and don’t that can be paired in the same way care (this time because POS is used, circle 0 and then inverse)
* Continue to pair until it can no longer be paired is the prime implicant we want
* Finally, the prime implicant is selected to select the smallest solution, and then replaced with a letter (ABCD), and expressed as POS
* Finally, output the results according to the operation regulations

## Program environment:
Implement on JAVA

