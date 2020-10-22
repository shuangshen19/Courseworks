#include<stdio.h>
#include<stdlib.h>
#define WEIGHT 50
// Returns max of two integers 
int max(int a, int b) {return (a > b)? a : b;} 
  
// Find the max value which can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n) 
{ 
	int i, w; 
	int K[n+1][W+1];  
	// Build table K[][] in bottom up manner 
	for (i = 0; i <= n; i++) 
	{ 
		for (w = 0; w <= W; w++) 
		{ 
			if (i==0 || w==0) K[i][w] = 0; 
			else if (wt[i-1] <= w) K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]], K[i-1][w]); 
			else K[i][w] = K[i-1][w]; 
		} 
	} 
	// Judge which item is chosen
	int j = W;
	int x[n];
    for(i = n; i >= 1; i--)
    {
        if(K[i][j]>K[i-1][j])
        {
			x[i]=1;
			j=j-wt[i-1];
        }
        else x[i]=0;
    }
    printf("The chosen items: ");
    for(i=1;i<=n;i++) printf("%d ",x[i]);
    printf("\n");
	return K[n][W]; 
} 

int main() 
{ 	
	// load the input file
    static const char filename1[] ="input.txt";
    FILE *fp = fopen(filename1, "r+");
    char line[10], *t;
    t = fgets(line, sizeof line, fp);
	int target, i;
    target = atoi(t); // how many items in the knapSack
	int val[target], wt[target];
	for(i = 0; i < target; i++)
	{
		t = fgets(line, sizeof line, fp);
		wt[i] = atoi(t);
	}
	for(i = 0; i < target; i++)
	{
		t = fgets(line, sizeof line, fp);
		val[i] = atoi(t);
	}
	
	// implement the knapSack
    for(i = 0; i < target; i++) printf("Weight:%d, Value:%d\n", wt[i], val[i]);
    int W = WEIGHT; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("The total number of items is: %d\n",n);
    printf("The solution is: %d", knapSack(W, wt, val, n)); 
    return 0;
} 
