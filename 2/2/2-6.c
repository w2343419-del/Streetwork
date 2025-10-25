#include <stdio.h>
int main( ) 
{
    char c4, c5, c6;
    c4 = '0';
    c5 = 0;
    c6 = c4 - 48;
	
    printf("c4=%d c5=%d c6=%d\n", c4, c5, c6);
    printf("c4=0x%x c5=0x%x c6=0x%x\n", c4, c5, c6);
    printf("c4=%c c5=%c c6=%c\n", c4, c5, c6);     
    
	return 0;
}



