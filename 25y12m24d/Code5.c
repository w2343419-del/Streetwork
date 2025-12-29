/*输入 n 个分数并对他们求和，并用化简。
最简形式是指分子分母的最大公约数为1；
若最终结果的分母为1，则直接用整数表示。

输入
每个输入包含一个测试用例，第1行输入 n (1≤n≤10)；
随后一行按格式 a1/b1 a2/b2 ... an/bn 的形式给出 n 个分数，
其中a1, a2, b1, b2, … ,an, bn都是整数，
题目保证所有分子和分母都在16位整型范围内，负数的符号一定出现在分子前面。

输出
如果输入的分数合法，以最简形式输出计算结果。
如果输入的分数无法计算，则输出error。

样例1
输入
2
1/2 1/3

输出
5/6
样例2

输入
2
-1/2 1/2

输出
0*/

#include <stdio.h>

typedef long long ll;

ll gcd(ll a, ll b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    ll sum_a = 0;
    ll sum_b = 1;

    for (int i = 0; i < n; i++) {
        ll next_a, next_b;
        char slash;
        
        if (scanf("%lld%c%lld", &next_a, &slash, &next_b) != 3 || slash != '/' || next_b == 0) {
            printf("error\n");
            return 0;
        }

        sum_a = sum_a * next_b + next_a * sum_b;
        sum_b = sum_b * next_b;

        if (sum_a == 0) {
            sum_b = 1;
        } else {
            ll common = gcd(sum_a, sum_b);
            sum_a /= common;
            sum_b /= common;
        }
    }

    if (sum_b < 0) {
        sum_a = -sum_a;
        sum_b = -sum_b;
    }

    if (sum_a == 0) {
        printf("0\n");
    } else if (sum_b == 1) {
        printf("%lld\n", sum_a);
    } else {
        printf("%lld/%lld\n", sum_a, sum_b);
    }

    return 0;
}