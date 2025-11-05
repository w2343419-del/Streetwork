/*
    描述
计算整数的平方根。

输入
第1行是一个整数
n
n，表示随后有
n
n组数据。每组数据占一行，包含一个整数
m
m，
−
10000
≤
m
≤
10000
−10000≤m≤10000。

输出
对每组数据
m
m，计算
m
m的平方根，精确到小数点后2位。如果
m
m没有平方根，则输出ERROR。

样例
输入

3
0
2
-1
输出

0.00
1.41
ERROR
*/
#include <stdio.h>
#include <math.h>
int main(){
    int n, m;
    double res;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        scanf("%d", &m);

        if (m<0){
            printf("ERROR\n");
        } else {
            double res = sqrt(m);
            printf("%.2lf\n", res);
        }
    }
    return 0;
}