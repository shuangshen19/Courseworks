#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void Merge(int original[], int temp[], int low, int mid, int high) 
{
	int len1, len2, i;
	// compare
	for(len1 = low, len2 = mid + 1, i = low; len1 <= mid && len2 <= high; i++) 
	{
		if(original[len1] <= original[len2]) temp[i] = original[len1++];
		else temp[i] = original[len2++];	
	}
	while(len1 <= mid) temp[i++] = original[len1++];
	while(len2 <= high) temp[i++] = original[len2++];
	for(i = low; i <= high; i++) original[i] = temp[i];
}

void Sort(int original[], int temp[], int low, int high) 
{
	int mid;
	// divide to sublists
	if(low < high)
	{
		mid = (low + high)/2;
		Sort(original, temp, low, mid);
		Sort(original, temp, mid + 1, high);
		Merge(original, temp, low, mid, high);		
	} 
	else return; 
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
    // start to do MergeSort
	Sort(sequence,temp,0,target-1);
	// write optputs to the output file
	static const char filename2[] ="output.txt";
    FILE *fp2 = fopen(filename2, "w+");
	fprintf(fp2,"%d\n", target);
	for(i = 0; i < target; i++) fprintf(fp2,"%d\n", sequence[i]);
	fclose(fp2);
    return 0;
}

