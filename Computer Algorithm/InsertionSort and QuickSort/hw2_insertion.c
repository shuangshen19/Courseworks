#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void insertionSort(int number[], int target) 
{
	int i, tem, tem2;
	for (i = 1 ; i < target; i++) 
	{
		tem = i;
		while ( tem > 0 && number[tem-1] > number[tem]) 
		{
			tem2 = number[tem];
			number[tem] = number[tem-1];
			number[tem-1] = tem2;
			tem--;
		}
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
	
	// implement the insertion sort
    insertionSort(sequence, target);
	
	// write optputs to the output file
	static const char filename2[] ="output.txt";
    FILE *fp2 = fopen(filename2, "w+");
	fprintf(fp2,"%d\n", target);
	for(i = 0; i < target; i++) fprintf(fp2,"%d\n", sequence[i]);
	fclose(fp2);
    return 0;
}

