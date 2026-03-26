/*3: 部分和问题
描述
给你 
N (N≤20) 个数，问你能不能从其中取出一些，让它们的和为 K.

输入
第一行包括两个数，N,K，分别代表整数个数，以及和 K。
接下来 N 行，每行一个整数。

输出
如果能选出一些数和为 K，输出YE5，否则，输出N0

样例1

输入
4 0
1
-1
2
3

输出
YE5

样例2

输入
2 2
1
-3

输出
N0

提示
请仔细阅读题面以及样例*/

#include <stdio.h>

int N, K;
int numbers[20];

int choose(int index, int sum) {
    if (sum == K) {
        return 1;
    } //得到解

    if (index == N) {
        return 0;
    } //数字用完，无解

    if (choose(index + 1, sum + numbers[index])) {
        return 1;
    } //选取左支（选择该数）

    if (choose(index + 1, sum)) {
        return 1;
    } //选取右支（不选择该数）

    return 0;
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        scanf("%d", &numbers[i]);
    }

    if (choose(0, 0) == 1) {
        printf("YE5\n");
    } else {
        printf("N0\n");
    }

    return 0;
}