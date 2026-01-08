/*描述
输入一个正整数 m（2 ≤ m ≤ 10⁸）。
找出最大的正整数 n，使得
  1² + 2² + 3² + … + n² < m。

例：设m = 30
1²+2²+3²+4² = 30
1²+2²+3² = 14 < 30 ⇒ 最大 n = 3

输入
一行，一个 32 位无符号整数 m。

输出
一个整数 n，满足上述条件。

样例
输入

30
输出

3
输入

2
输出

1*/
#include <stdio.h>
int main() {
    unsigned int m;
    scanf ("%u", &m);

    unsigned int n = 0;
    unsigned long long int sum = 0;
    while (sum + ( n + 1 ) * ( n + 1 ) < m) {
        n++;
        sum = sum + n * n;
    }
    printf ("%u\n", n);
    return 0;
}