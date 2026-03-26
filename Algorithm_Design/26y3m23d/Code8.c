/*8: 选数
描述
已知 n 个整数 x1,x2,…,xn ,以及 1 个整数 k (k<n)。
从 n 个整数中任选 k 个整数相加,可分别得到一系列的和。

例如当 n = 4, k = 3, 4个整数分别为 3,7,12,19 时，可得全部的组合与它们的和为：
3+7+12=22
3+7+19=29
7+12+19=38
3+12+19=34

现在，要求你计算出和为素数共有多少种。
例如上例，只有一种的和为素数：3+7+19=29。

输入
第一行两个空格隔开的整数 n, k (1 ≤ n ≤ 20, 1 ≤ k < n)。

第二行 n 个整数，分别为
x1, x2, …, xn(1 ≤ xi ≤ 5 × 10 ^ 6)

输出
输出一个整数，表示种类数。

样例
输入

4 3
3 7 12 19
输出

1*/

#include <stdio.h>
#include <math.h>

int N, K;
int nums[20];
int count = 0;

int is_prime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void dfs(int index, int selected, int sum) {
    if (selected == K) {
        if (is_prime(sum) == 1) {
            count++;
        }
        return;
    }

    if (index == N) return;

    dfs(index + 1, selected + 1, sum + nums[index]);

    dfs(index + 1, selected, sum);
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &nums[i]);
    }

    dfs(0, 0, 0);

    printf("%d\n", count);

    return 0;
}