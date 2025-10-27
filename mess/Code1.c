#include <stdio.h>
int main()
{
    int f;
    float c;
    scanf("%d",&f);

    if (f<=0)
    {
        printf("error\n");
        return 0;
    }

    else
    {
        c=(5.0/9.0)*(f-32.0);
        printf("%.2f\n",c);
        return 0;
    }
}