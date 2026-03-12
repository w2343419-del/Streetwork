/*对于一个五位数 a1a2a3a4a5，可将其拆分为三个子数：sub1 = a1a2a3  sub2 = a2a3a4  sub3 = a3a4a5
例如，五位数 20207 可以拆分成
sub1 = 202
sub2 = 020 (=20)
sub3 = 207

现在给定一个正整数 K，要求你编程求出 10000 到 30000 之间所有满足下述条件的五位数，
条件是这些五位数的三个子数 sub1, sub2, sub3 都可被 K 整除。

输入格式
一个正整数 K。

输出格式
每一行为一个满足条件的五位数，要求从小到大输出。不得重复输出或遗漏。如果无解，则输出 No。

输入输出样例

输入
15

输出
22555
25555
28555
30000

说明/提示
0 < K < 1000*/

#include <stdio.h>
int main() {
    int K;
    scanf("%d", &K);

    int found = 0;

    for (int num = 10000; num <= 30000; num++) {
        int a, b, c, d, e;
        a = num / 10000;
        b = (num / 1000) % 10;
        c = (num / 100) % 10;
        d = (num / 10) % 10;
        e = num % 10;

        int sub1 = a * 100 + b * 10 + c;
        int sub2 = b * 100 + c * 10 + d;
        int sub3 = c * 100 + d * 10 + e;

        if (sub1 % K == 0 && sub2 % K == 0 && sub3 % K == 0) {
            printf("%d\n", num);
            found = 1;
        }
    }

    if (!found) {
        printf("No\n");
    }
    
    return 0;
}