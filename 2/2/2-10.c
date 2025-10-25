#include <stdio.h>
void main()
{
    int a=5;
    int b,c;
    int i=10;
    b=a++;
    c=++b;
    
    printf("a = %d, b = %d, c = %d\n",a,b,c);
    printf("%d\n",++i);
    printf("%d\n",--i);
    printf("%d\n",i++);
    printf("%d\n",i--);
    printf("%d\n",-i++);
    printf("%d\n",-i--);
    getchar();
}



