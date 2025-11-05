/*
描述

输入2个整数m,n（0<m,n<1000)，计算mn之间的所有奇数的和。

输入

第1行是一个整数x，表示随后有x组数据。每组数据占一行，输入的整数用空格隔开。

输出

对每组数据，输出mn之间的所有奇数的和，并换行

样例

输入           输出
2
1    6            9
14  8        33
*/
#include <stdio.h>
int main(){
    int m, n, sum;
    int x;
    scanf("%d", &x);
    for (int i = 0; i < x; i++){
        scanf("%d %d", &m, &n);
        sum = 0;
        int max, min;
        if ( m > n ){
            max = m;
            min = n;
        }
        else{
            max = n;
            min = m;
        }
        for (int a = min; a <= max; a++){
            if ( a%2 == 1 ){
                sum = sum + a;
            }
        }
        printf("%d\n", sum);
    }
}


