#include <stdio.h>

int main(void)
{
    int a=1,b=1,m;
    while(b<=9)
    {
        while(a<=9)
        {
            m=a*b;
            printf("%d*%d=%-2.d ",a,b,m);
            a++;
        }
        if(a=1) printf("\n");
        b++;
    }
    return 0;
}
