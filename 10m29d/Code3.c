/*
描述

输入一个整数n（n> 0），计算1/2+2/3+3/4+4/5+。。。前n项的值，结果保留4位小数

输入

第1行是一个整数n，表示随后有n组数据。每组数据占一行。

输出

每组输入的结果保留4位小数，并换行。

样例

输入           输出

1

2              1.1667


*/
#include <stdio.h>
int main(){
    int n;
    double sum = 0.0;
    scanf("%d", &n);
    
    for ( int i = 1; i <= n; i++) {
        sum = 0.0;
        int a;
        scanf("%d", &a);
        
        for ( int j = 1; j <= a; j++){
            sum =sum +j/(j+1.0);
        }
        
        printf ("%.4lf\n", sum);
    }
      
    return 0;
}