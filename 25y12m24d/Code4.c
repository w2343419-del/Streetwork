/*如果矩阵中某元素是其所在行的最大值、同时又是其所在列的最小值，则称其为“鞍点”。
给定一个 n×m 矩阵（1≤n,m≤15），输出所有鞍点的行、列坐标（行列编号都从 0 开始），若无则输出 none。

输出格式：
输入
第一行：两个整数 m 、n，（1≤m,n≤15）
接下来 m 行：每行 n 个整数， −100 ≤ 整数 ≤ 100 ，中间用空格分隔。

输出
每行一个鞍点坐标 i j，中间用空格分隔，如有多个，输出顺序按行优先顺序；如果不存在鞍点则输出 none。

样例
输入1
3 3
3 7 6
9 11 10
15 16 17

输出1
0 1

输入2
3 3
33 37 36
19 41 14
15 16 27

输出2
none*/

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int a[15][15];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int found = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int isRowMax = 1;
            for (int k = 0; k < n; k++) {
                if (a[i][k] > a[i][j]) {
                    isRowMax = 0;
                    break;
                }
            }

            int isColMin = 1;
            for (int k = 0; k < m; k++) {
                if (a[k][j] < a[i][j]) {
                    isColMin = 0;
                    break;
                }
            }

            if (isRowMax && isColMin) {
                printf("%d %d\n", i, j);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("none\n");
    }

    return 0;
}
