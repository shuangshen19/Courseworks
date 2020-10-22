# Algorithm: Backpack Problem

## Brief description:
Given n items and a backpack, the weight of item i is wi, its value is vi, and the capacity of the backpack is W. How should I choose the items to be loaded into the backpack so that the total value of the items loaded into the backpack is maximized? When selecting items, there are only two options for each item i (packing in a backpack or not loading it). You cannot choose to load the item multiple times, or just load a part of the item.

The input of the program is explained below, and the weight of the backpack is defined in the third line of the program;
First write the total number of backpacks that can be loaded and the amount and value of each item in input.txt, as shown in the following figure, the first line is the total number of backpack items, followed by the weight, and then the value.
`Weight[] = {10,20,30}, Value[] = {60,100,120}`

In order to consider a subset of all items, each item can have two situations:
(1) Items are included in the best subset, (2) Not included in the best set.
``` c
if (i==0 || w==0) K[i][w] = 0
if (wt[i-1] <= w) K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i- 1][w]);
```

The analysis problem can be divided into two categories. If the weight of the i-th item is greater than the capacity of the backpack, the maximum value obtained by loading the first i items and the maximum price obtained by loading the first i-1 items are the same, that is, item i Cannot be loaded into the backpack; and if the weight of the i-th item is less than the capacity of the backpack, there will be two situations:
* If the i-th item is loaded into the backpack, the value of the backpack item is equal to the value of the i-1th item loaded into the backpack with the capacity bit W-wi plus the value v of the i-th item
* If the i-th item is not loaded into the backpack, the value of the items in the backpack is equal to the value obtained by putting the first i-1 items into the backpack with a capacity of W

Obviously, the highest value of the two is taken as the optimal solution for putting the first i items into a backpack with a capacity of W, and the same sub-problem can be avoided by bottom-up. Therefore, the maximum value that can be obtained from n items is the maximum of the following two values:
* The maximum value obtained by n-1 item and W weight (not including the nth item)
* The value of the nth term plus the maximum value obtained by the n-1 term and W minus the weight of the nth term (including the nth term)


## Program environment:
Implement on C (Dev C++, GCC 4.9.2)

