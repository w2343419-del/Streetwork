/*【模拟题 B：矩阵边界检查】
给定一个 N * N 的矩阵，输出所有位于“副对角线”上方（不包括对角线本身）的元素之和。
输入：第一行是 N。接下来是 N * N 个整数。
关键公式：对于矩阵元素 a[i][j], 副对角线的特征是 i + j = N - 1。*/

#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    int a[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i + j < N - 1) {
                sum = sum + a[i][j];
            }
        }
    }

    printf("%d", sum);
    return 0;
}