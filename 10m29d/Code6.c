/*
描述
给定一个32位带符号整数 n，计算其各位数字之和（忽略符号）。

输入
一个整数 n（32位带符号整数）。

输出
一个整数，表示 n 的各位数字之和。

样例
输入

1234
输出

10
输入

-12
输出

3
*/ 
#include <stdio.h>
#include <stdlib.h>
int main(){
	int n;
	scanf("%d", &n);
	n = abs(n);
	int sum = 0;
	
	while (n != 0){
		sum = sum + n % 10;
		n = n / 10;
	}
	
	printf ("%d", sum);
	return 0;
}