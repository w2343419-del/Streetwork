/*
描述
利用海伦公式求三角形面积。海伦公式为：
s=p(p−a)(p−b)(p−c)开方
​其中，a,b,c  a,b,c 分别代表三角形的三条边的边长，p=(a+b+c)/2

输入
第1行是一个整数n，表示随后有
n组数据。每组数据占一行，包含三个整数
a、b、c，以空格隔开，分别代表三角形的三条边的边长。

输出
对每组数据，如果a、b、c能构成三角形，则输出三角形的面积，结果保留两位小数；如果不能构成三角形，则输出error，并换行。

样例
输入

3        
2 3 4
2 3 5    
3 4 5 
输出

2.90
error
6.00
*/
#include <stdio.h>
#include <math.h>
int main(){
    int n, a, b, c;
    double p, s;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        if(a+b>c && b+c>a && c+a>b && a>0 && b>0 && c>0){
            p = (a+b+c)/2.0;
            s = sqrt(p*(p-a)*(p-b)*(p-c));
            printf("%.2lf\n",s);
        }
        else{
            printf("error\n");
        }
    }
    return 0;
}