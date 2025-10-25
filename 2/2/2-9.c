#include <stdio.h>
int main( ) 
{
    int i = 2.3, k = 309, m = 65536;
    char c = 49; 
    short sa = -1;
    unsigned short ss = 0;
    float f;
    double d = 123.456789e10;        
    
	printf("i = %d\n", i);
	printf("c = %c\n", c);
	c = k;
    printf("c = %c k = %x\n", c, k);
    ss = sa;
    printf("ss = %d\n", ss);
    sa = m;
    printf("sa = %d\n", sa);
    f = d;
    printf("f = %f\n", f);
    
	return 0;
}



