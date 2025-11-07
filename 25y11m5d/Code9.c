/*
描述
输入两个正整数 m 和 n，输出 m 和 n 的最大公约数。
输入
第 1 行是一个整数 T，表示随后有 T 组数据。每组数据占一行，包含两个整数，用空格隔开。
输出
对每组数据输出两个整数的最大公约数，并换行。
样例
输入
3
2 5
4 6
3 9
输出
1
2
3*/
#include <stdio.h>
int main() {
    int t, m, n;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &m, &n);
        int a = m, b = n;
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
    printf ("%d\n", a);
    }
}