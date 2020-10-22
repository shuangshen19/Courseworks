#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
    double x;
    printf("please input a number: ");
    scanf("%lf",&x);
    int y = (int)x;
    char str[y];
    double z = x-y;
    char t[] = ".";
    sprintf(str,"%lf",z);
    char *test = strtok(str, ".");
    int i =0;
    char *te[i];
    while(test!=NULL)
    {
        te[i]=test;
        test = stroke(NULL,".");
        i++;
    }
    printf("change = %s.%d\n",te[1],y);
    return 0;
}
