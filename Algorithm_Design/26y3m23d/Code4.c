/*4: 全排列问题
描述
生成 1,2,⋯,N (1≤N<10) 的全排列。

输入
第一行包括一个整数 N

输出
按字典序输出 1,2,⋯,N 的所有全排列。

样例

输入
3

输出
123
132
213
231
312
321*/

#include <stdio.h>

int N;
int nums[10];
int used[10];

void perm(int pos) {
    if (pos == N) {
        for (int i = 0; i < N; i++) {
            printf("%d", nums[i]);
        }
        printf("\n");
        return;
    }

    for (int j = 1; j <= N; j++) {
        if (used[j] == 0) {
            used[j] = 1;
            nums[pos] = j;
            perm(pos + 1);
            used[j] = 0;
        }
    }
}

int main() {
    scanf("%d", &N);
    perm(0);
    return 0;
}