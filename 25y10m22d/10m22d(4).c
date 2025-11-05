/*
描述
输入圆的圆心坐标 (cx, cy) 和半径 r（r>0），再输入一个点 (px, py)。
若点 严格位于圆内（不包括边界），输出 1；否则输出 0。

输入
一行， 输入5个整数：cx cy r px py

输出
点在圆内输出1，否则输出0。

样例
输入

0 0 5 3 4
输出

0
输入

0 0 5 3 3
输出

1
*/
#include <stdio.h>
int main() {
    int cx, cy, r, px, py;
    scanf("%d %d %d %d %d", &cx, &cy, &r, &px, &py);
    if (((cx-px)*(cx-px)+(cy-py)*(cy-py))<r*r)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    return 0;
}