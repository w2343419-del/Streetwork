/*
描述

输入一个正整数，输出它的二进制中包含几个1

输入

第1行是一个整数n，表示随后有n组数据。

每组数据占一行，包含一个正整数。

输出

对于每一组数据，输出二进制中1的个数。

样例

输入

输出

2

10

100

2

3
*/
#include <stdio.h>
int main() {
    int n;
    scanf ("%d", &n);

    for (int i = 0; i < n; i++){
        int num;
        scanf ("%d", &num);
        
        int sum = 0;
        while ( num > 0 ) {
            if ( num % 2 == 1 ) {
                sum++ ;
            }
            num = num >> 1;
        }
        printf ("%d\n", sum);
    }  
    return 0;  
    
}