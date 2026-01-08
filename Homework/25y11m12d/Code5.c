/*描述
给定一个带符号 32 位整数 n，
把 n 的十进制表示中所有“奇数位数字”与“偶数位数字”交换，然后输出交换后的整数（保持原符号，忽略前导 0）。

奇数位：从左往右数第 1、3、5…位；偶数位：第 2、4、6…位

输入
一个整数 n（32位带符号整数）。

输出
一个整数，表示交换后的整数。

样例
输入

1234
输出

2143
输入

-123
输出

-213*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    int n;
    scanf("%d", &n);

    char s[33];
    sprintf(s, "%d", n);

    int start_index = 0;
    if (s[0] == '-') {
        start_index = 1;
    }

    int len = strlen(s);
    for (int i = start_index; i < len - 1; i += 2){
        char temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
    }

    int result = atoi(s);
    
    printf ("%d", result);
    return 0;
}