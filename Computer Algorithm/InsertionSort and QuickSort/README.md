# Algorithm: InsertionSort and QuickSort 

## Brief description:
At the beginning, the program reads the number sequence in input.txt (arrangement method is as specified in the title), and there is a program that can output 10000 random numbers (hw2_rand.c), and write the result after Sort into output.txt.

## InsertionSort:
Insertion Sort is to take out the elements in the unsorted sequence one by one, and insert them from the back to the front of the sorted sequence. In simple terms, the program can be divided into the following three steps: (hw2_insertion.c)
* Element comparison, if it is larger than itself, shift the element to the right
* Repeat the action of 2 until you encounter an element that is no greater than yourself, write the temporary variable after the element; if there is none, write it at the top
* Repeat the above actions until all unsorted parts are processed

## QuickSort:
QuickSort will select a pivot from all the data, then move all the data smaller than the pivot before the pivot, and move all the data larger than the pivot after the pivot, and finally sort. In simple terms, the program can be divided into the following three steps: (hw2_quick.c)
* Start from the far left of the data and look for a number larger than the fulcrum; and from the far right of the data, look for a number smaller than the fulcrum, and exchange the two data
* Repeat the same action until the data is divided into less than and greater than the pivot point, and then move the pivot point between the two
* After Partition, perform the same action of selecting pivots and moving them until the complete sorting is completed.

## Improvement:
Improved to use quick sort and insertion sort at the same time to improve execution efficiency; first judge k and use quick sort if the size is greater than k, and then use insertion sort. (hw2_7.4-5.c)
* In the case of fewer elements: insertion sort performs better
* In the case of more elements: quick sort performs better

## Program environment:
Implement on C (Dev C++, GCC 4.9.2)