# Algorithm: MergeSort 

## Brief description:
Merge sort is a sorting technology based on the "Divide-and-Conquer" strategy. In the worst case, the time complexity is O(n logn).

At the beginning of the program, read the number sequence in input.txt (arrangement method is as specified in the title), and write the result of executing MergeSort into output.txt; there are two functions (Merge and Sort) in the program, and Sort will The sequence is split into two parts, and the sequence is repeatedly split by recursion until the sequence is completely split, then Merge is called, and the two decimal sequences are compared by Merge, and the number of the larger sequence is put into the temp array, After comparing the size, put the number originally in temp back to the original number sequence and repeat until all sorting is completed. The program can be simply divided into the following three steps.
* Cut the original Data List into two equal parts
* Sort the left and right Sublists by MergeSort
* Merge the two Sublists in the left and right half into a new Data List