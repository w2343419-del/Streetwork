/*【模拟题 A】
输入一个正整数 n (1 <= n <= 1000)，计算并输出以下级数的前 $n$ 项之和，结果保留 3 位小数。
S = 1 / (1 * 2) + 1 / (2 * 3) + 1 / (3 * 4) + ... + 1 / (n * (n + 1))*/

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    double sum = 0;
    double temp = 0;
    for (int i = 1; i <= n; i++) {
        temp = 1.0 / (i * (i * (i + 1)));
        sum = sum + temp;
    }
    printf("%.3f", sum);
    return 0;
}