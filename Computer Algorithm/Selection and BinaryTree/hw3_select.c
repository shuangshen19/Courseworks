#include <stdio.h>
#include<string.h>
#include <stdlib.h>
#define swap(x,y) {int t; t = x; x = y; y = t;}

int selectionAlgorithm(int sequence[], int l, int r, int k) 
{
    if(r-l+1 <= 5) 
	{
		// insertion sort
        int i, j, v;
        for(i = l+1; i <= r; i++) 
		{
            v = sequence[i], j = i;
            while(j-1 >= l && sequence[j-1] > v)
            {
            	sequence[j] = sequence[j-1];
				j--;
			}
            sequence[j] = v;
        } 
        return l+k;
    }

    int pivot = medianOfMedians(sequence, l, r);
    // partition begin
    swap(sequence[l], sequence[pivot]);
    int i, j, t = sequence[l];
    for(i = l, j = l+1; j <= r; j++) 
	{
        if(sequence[j] <= t) 
		{
			i++;
			swap(sequence[i], sequence[j]);
		}
    }
    swap(sequence[l], sequence[i]);

    // find the location
    int position = i;
    if(position-l == k) return position;
    if(position-l < k) return selectionAlgorithm(sequence, position+1, r, k-(position-l+1));
    else return selectionAlgorithm(sequence, l, position, k);
}

int medianOfMedians(int sequence[], int l, int r) 
{
	// find the medians
    int numM = (r-l+4)/5;
    int i, subl, subr;
    int medianIdx;
    for(i = 0; i < numM; i++) 
	{
        subl = l + i*5;
        subr = subl + 4;
        if(subr > r) subr = r;
        medianIdx = selectionAlgorithm(sequence, subl, subr, (subr-subl)/2);
        swap(sequence[l+i], sequence[medianIdx]);
    }
    return selectionAlgorithm(sequence, l, l+numM, numM/2);
}

int main() 
{
	// load the input file
    static const char filename1[] ="input.txt";
    FILE *fp = fopen(filename1, "r+");
    char line[10], *t;
    t = fgets(line, sizeof line, fp);
	int target, i;
    target = atoi(t); // how many numbers in the sequence
	int sequence[target], temp[target];
	for(i = 0; i < target; i++) temp[i] = 0;
	for(i = 0; i < target; i++)
	{
		t = fgets(line, sizeof line, fp);
		sequence[i] = atoi(t);
	}
	
	int search;
	printf("Please input the number which you want to find and the range is 1 ~ %d\n", target);
	int idx = selectionAlgorithm(sequence, 0, target-1, 0);
	
	// write optputs to the output file
	static const char filename2[] ="output.txt";
    FILE *fp2 = fopen(filename2, "w+");
	fprintf(fp2,"%d\n", target);
	for(i = 0; i < target; i++) fprintf(fp2,"%d\n", sequence[i]);
	fclose(fp2);
	
    // search the number and return the value
    while(scanf("%d", &search) == 1) 
	{
        idx = selectionAlgorithm(sequence, 0, target-1, search-1);
        printf("The value in this index is: %d\n", sequence[idx]);
    }
    return 0;
}
