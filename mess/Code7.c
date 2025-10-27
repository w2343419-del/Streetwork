#include <stdio.h>
int main()
{
    int n, a, b, c, d, result;
    scanf("%d",&n);
    a=n/1000;
    b=(n/100)%10;
    c=(n/10)%10;
    d=n%10;
    result=a+b+c+d;
    
    if (n<1000 || n>9999){
        printf("illegal");
        return 0;
    }
    
    else {
    printf("%d",result);
    return 0;
    }
    
}