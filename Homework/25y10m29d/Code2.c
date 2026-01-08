/*
描述

输入一个偶数n（n> 0），计算1/2+1/4+...+1/n，结果保留4位小数

输入

第1行是一个整数m，表示随后有m组数据。每组数据占一行。

输出

每组输入的结果保留4位小数，并换行。

样例

输入           输出

2

6              0.9167

8             1.0417


*/
#include <stdio.h>
int main() {
    int m, n;
    double sum = 0.0000;
    scanf ( "%d", &m );

    for ( int i = 1; i <= m; i++ ) {
        scanf ( "%d", &n );
        sum = 0.0000;
        
        for ( int j = 1; j <= n; j++ ) {
            if ( ( j % 2 ) == 0 ) {
                sum = sum + ( 1.0 / j );
            }
        }
        printf ("%.4lf\n", sum);
        
    }
    return 0;
}