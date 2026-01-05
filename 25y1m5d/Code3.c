/*给定0-9数字各若干个，以任意顺序排列这些数字，使得最后得到的数尽可能小（0 不能做首位）。

输入
在一行中给出 10 个非负整数，顺序表示数字 0、数字 1、……数字 9 的个数。
整数间用一个空格分隔。10 个数字的总个数不超过 50，且至少拥有 1 个非 0 的数字。

输出
在一行中输出能够组成的最小的数。

样例
输入
2 2 0 0 0 3 0 0 1 0

输出
10015558*/

#include <stdio.h>
int main() {
    int counts[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &counts[i]);
    }

    for (int i = 1; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d", i);
            counts[i]--;
            break;
        }
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < counts[i]; j++) {
            printf("%d", i);
        }
    }
    printf("\n");
    return 0;
}
