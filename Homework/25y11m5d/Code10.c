/*描述
输入正整数a,b,c，输出a/b的小数形式，精确到小数点后c位(不考虑四舍五入)。2 <= a,b,c <= 1000。（注意本题小数保留范围）。
输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，输入正整数a，b，c (2<=a,b,c<=1000)，用空格隔开。
输出
对每组数据，计算并输出a/b的小数形式，保留小数点后c位，并换行，
样例
输入
3
2 3 20
2 6 10
6 7 3
输出
0.66666666666666666666
0.3333333333
0.857*/
#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
 
    for (int i = 1; i <= n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        printf ("%d.", a / b);
        
        int d = a % b;
        for (int j = 0; j < c; j++){
            d = d * 10;
            int e = d / b;
            printf ("%d", e);
            d = d % b;
        }
        printf ("\n");
    }
    return 0;
}