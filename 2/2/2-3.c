#include <stdio.h>

int main()
{
    short a;
    unsigned short b;
	
    a = -1;
    b = 65535;
	
    printf("a=%d b=%d\n", a, b);
    printf("a=%hu b=%hu\n", a, b);
    printf("a=%hx b=%hx\n", a, b);     
     
    return 0;
}


