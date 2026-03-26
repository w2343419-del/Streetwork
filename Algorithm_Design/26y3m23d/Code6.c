/*6: 整数划分问题
描述
将正整数 n 表示成一系列正整数之和n = n1 + n2 + ⋯ + nk
其中，
n1 ≥ n2 ≥ ⋯ ≥ nk ≥ 1
正整数 n 的这种表示称为正整数 n 的划分，正整数 n 的不同的划分个数称为正整数 n 的划分数，
记作 p(n)。
例如，正整数 6 有如下 11 种不同的划分，即 p(6)=11，
6 = 6;
6 = 5 + 1;
6 = 4 + 2;
6 = 4 + 1 + 1;
6 = 3 + 3;
6 = 3 + 2 + 1;
6 = 3 + 1 + 1 + 1;
6 = 2 + 2 + 2;
6 = 2 + 2 + 1 + 1;
6 = 2 + 1 + 1 + 1 + 1;
6 = 1 + 1 + 1 + 1 + 1 + 1;

输入
多组数据，每组数据包含一个正整数 n (1≤n≤20) 。

输出
每组数据输出一行，正整数 n 的划分数 p(n)。

样例
输入
1
2
6

输出
1
2
11*/

#include <stdio.h>

int count;

void dfs(int rest, int max) {
    if (rest == 0) {
        count++;
        return;
    }

    for (int i = max; i >= 1; i--) {
        if (i <= rest) {
            dfs(rest - i, i);
        }
    }
}

int main() {
    int n;

    while (scanf("%d", &n) == 1) {
        count = 0;
        dfs(n, n);
        printf("%d\n", count);
    }
    
    return 0;
}
