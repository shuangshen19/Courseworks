#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define swap(x,y) {int t; t = x; x = y; y = t;} 

int partition(int number[], int left, int right) 
{ 
    int i = left - 1; 
    int j;
    for(j = left; j < right; j++) 
	{ 
        if(number[j] <= number[right]) 
		{ 
            i++; 
            swap(number[i], number[j]); // change numbers
        } 
    } 
    swap(number[i+1], number[right]); 
    return i+1; 
} 

void quickSort(int number[], int left, int right) 
{ 
    if(left < right) 
	{ 
        int q = partition(number, left, right); 
        quickSort(number, left, q-1); 
        quickSort(number, q+1, right); 
    } 
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
    
    // start quicksort
	quickSort(sequence, 0, target-1);
	
	// write optputs to the output file
	static const char filename2[] ="output.txt";
    FILE *fp2 = fopen(filename2, "w+");
	fprintf(fp2,"%d\n", target);
	for(i = 0; i < target; i++) fprintf(fp2,"%d\n", sequence[i]);
	fclose(fp2);
    return 0;
}

