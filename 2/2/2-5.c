#include <stdio.h>

int main()
{
	char c1, c2, c3;
	
	c1 = 97;
	c2 = 'a';
	c3 = c2 - 32;
	
	printf("c1=%d c2=%d c3=%d\n", c1, c2, c3);
	printf("c1=0x%x c2=0x%x c3=0x%x\n", c1, c2, c3);
	printf("c1=%c c2=%c c3=%c\n", c1, c2, c3);
	
	return 0;
}




