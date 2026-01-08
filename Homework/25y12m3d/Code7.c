/*根据输入的数据打印柱状图。
例如输入 4 1 3 2 4，输出下面的柱状图：
---*
-*-*
-***
****
第一个 4 表示后面有 4 个数据，随后的 1 3 2 4 分别代表每列 * 的个数，柱状图的高度由输入数据中的最大值决定。空白的地方用 - 填充。
例如输入 5 0 5 2 3 1，输出下面的柱状图：
-*---
-*---
-*-*-
-***-
-****

输入
首先是一个正整数 n (1≤n≤10)，后面跟随 n 个整数 m (0≤m≤10)，均以空格隔开。

输出
输入合法时，输出柱状图见样例。若输入不合法，则输出 Input Error。

样例

输入
3 0 4 1

输出
-*-
-*-
-*-
-** */

#include <stdio.h>

int main() {
    int n;
    int data[10];
    int max = 0;

    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Input Error");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
        
        if (data[i] < 0 || data[i] > 10) {
            printf("Input Error");
            return 0;
        }

        if (data[i] >= max) {
            max = data[i];
        }
    }

    for (int i = max; i > 0; i--) {
        for (int j = 0; j < n; j++) {
            if (data[j] >= i) {
                printf("*");
            } else {
                printf("-");
            }
        }
        printf("\n");
    }
    return 0;
}
