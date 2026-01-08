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
9=2^3+2^0 */
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d=", n);
    
    int first = 1;
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            if (!first) {
                printf("+");
            }
            first = 0;
            
            if (i == 0) {
                printf("2^0");
            } else if (i == 1) {
                printf("2^1");
            } else {
                printf("2^%d", i);
            }
        }
    }
    
    return 0;
}