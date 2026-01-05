/*任何一个正整数都可以用 2 的幂次方表示。例如 138=2^7+2^3+2^1。
请编程输出给定正整数的幂次表达式。

输入
输入 1 个十进制正整数，范围是1~100000。

输出
输出它的幂次表达式，按幂次降序排列。

样例
输入
2

输出
2=2^1

输入
9

输出
9=2^3+2^0*/

#include <stdio.h>
#include <math.h>
int main() {
    int n;
    scanf("%d", &n);
    printf("%d=", n);
    
    int power;
    int x;
    
    for (int x = 16; x >= 0; x--) {
        power = pow(2, x);
        if (n >= power) {
            n -= power;
            printf ("2^%d", x);
            if (n != 0) {
                printf("+");
            }
        }
    }
    return 0;
}