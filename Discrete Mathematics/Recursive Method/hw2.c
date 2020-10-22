#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void recursion(int result[], int n, int k, int a, int t, int length)
{
    int i;
    
    // t is a label to choose number
	if(t<=length)
	{
		for(i = a; i < n+1; i++)
		{
			result[t-1] = i;  // store a number we choose in the result array
			t++;
			recursion(result,n,k,i+1,t,length);  // excution to the last then return
			t--;
		}
	}
	else
	{
		// create a string to print
		char s[t-1];
		// store every number we choose in a string
		for(i=0;i<t-1;i++) sprintf(&s[i], "%d", result[i]);
        // print the answer
		for(i=0;i<t-1;i++) printf("%c ",s[i]);  
        printf("\n");
	}
}


int main()
{
	int n, k;
	
	printf("How many combinations to select k number from n number?\n");
    printf("Please input n: ");
	scanf("%d",&n);
    printf("Please input k: ");
	scanf("%d",&k);
	
	int result[k];

	// if the format of C(n,k) is correct
	if(n > 0 && k > 0 && n >= k)  
	{
		recursion(result,n,k,1,1,k);
	}
	// if the format isn't correct, please re-enter
	else
	{
		printf("Wrong input! Please re-enter.");
	}

	return 0;
}
