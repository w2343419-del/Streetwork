#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d", &a, &b);
    c=a+b;

    if (c>0)
    {
        printf("0");
        return 0;
    }

    else 
    {
        printf("%d\n",c);
        return 0;
    }
}