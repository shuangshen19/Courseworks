#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int main()
{
	srand(time(NULL));
	
	int min = 0;
	int max = 10000;
	int target = 10000;
	int i;
	// generate inputs
	static const char filename2[] ="input.txt";
    FILE *fp2 = fopen(filename2, "w+");
	fprintf(fp2,"%d\n", target);
	for(i = 0; i < target; i++) 
	{
		int x = rand() % (max - min + 1) + min;
		fprintf(fp2,"%d\n", x);
	}
	fclose(fp2);
    return 0;
}

