/*
描述
从键盘输入 
a
,
b
,
c
a,b,c 三个整数，作为三角形的三条边长，判断这是一个直角/锐角/钝角三角形？

输入
第1行是一个整数 
n
n，表示随后有 
n
n 组数据。每组数据占一行，依次输入三个整数，分别表示 
a
,
b
,
c
a,b,c，数字间用逗号隔开。

输出
如果是锐角三角形，输出字符串 acute
如果是直角三角形，输出字符串 right
如果是钝角三角形，输出字符串 obtuse
如果无法构成三角形，输出字符串 illegal
样例
输入

3
3,4,5
1,2,1
6,5,4
输出

right
illegal
acute
*/
#include <stdio.h>
int main(){
    int n, a, b, c, max, mid, min;
    double res1, res2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        scanf("%d,%d,%d", &a, &b, &c);

        if (a >= b && a >= c){
            max = a;
            if(b >= c){
                mid = b;
                min = c;
            }else{
                mid = c;
                min = b;
            }
        }else if(b >= a && b >= c){
            max = b;
            if(a>=c){
                mid = a;
                min = c;
            }else{
                mid = c;
                min = a;
            }
        }else{
            max = c;
            if(a >= b){
                mid = a;
                min = b;
            }else{
                mid = b;
                min = a;
            }
        }
        res1 = max*max;
        res2 = mid*mid + min*min;
        if((min +mid) <= max){
            printf("illegal\n");
            continue;
        }else if(res1 > res2){
            printf("obtuse\n");
            continue;
        }else if(res1 == res2){
            printf("right\n");
            continue;
        }else{
            printf("acute\n");
            continue;
        }
    }
    return 0;
}