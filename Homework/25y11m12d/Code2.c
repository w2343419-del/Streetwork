/*描述
任何大于 6 的偶数都可以分解成两个奇质数的和。输入 n，输出所有解，按小的在前，大的在后输出，不要重复。

输入
每行输入包含一个测试用例，输入一个 n (n≤10000000)。

输出
对符合要求的输入数据，依次输出所有解，每个解占一行，两个数用空格分隔。对输入不符合要求的数，则输出ERROR。

样例
输入

10

输出

3 7
5 5*/
#include <stdio.h>
#include <math.h>
int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n <= 6 || n % 2 != 0) {
            printf("ERROR\n");
        } else {
            int found = 0;
            for (int i = 3; i <= n / 2; i += 2) {
                if (is_prime(i) && is_prime(n - i)) {
                    printf("%d %d\n", i, n - i);
                    found = 1;
                }
            }
            if (!found) {
                printf("ERROR\n");
            }
        }
    }
    return 0;
}