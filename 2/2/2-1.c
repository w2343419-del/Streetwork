#include <stdio.h>
int main( ) 
{
    int a1 = 17, a2 = 5;
	int res1 = 0;
	double b1 = 17.0, b2 = 5.0;
	double res2 = 0.0; 
	
	res1 = a1 / a2;
	res2 = a1 / b2;
	printf("a/b=%d\n", res1);
	printf("a/b=%.2f \n", res2);
	
	return 0;
}


