/*描述
输入一个 32 位带符号整数 n（n > 0）。
不断重复以下步骤，直到 n 变成一位数为止：
把 n 的各位数字相加，得到一个新的整数；
用新整数替换原来的 n。
输出最终得到的那一位数字。

例：
9875 → 9+8+7+5 = 29
29 → 2+9 = 11
11 → 1+1 = 2

输入
一个正整数 n。

输出
一个整数，表示 n 的数字根（一位数）。

样例
输入

9875
输出

2
输入

7
输出

7*/
#include <stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    while (n >= 10) {
        int sum = 0;
        int temp = n;
        while ( temp > 0 ) {
            sum = sum + temp % 10;
            temp = temp / 10;
        }
        n = sum;
    }

    printf ("%d\n", n);
    return 0;

}