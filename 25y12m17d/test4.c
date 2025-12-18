/*你开了一家火锅店，店里举行辣度挑战赛，准备了一口包含 n×m个格子 的巨型锅（每格都都有一个辣度值）。
顾客会甩给你一个固定尺寸 w×h ，你必须瞬间算出所有 w×h 矩形区域的总辣度，并找出全场最辣的那一块矩形。
如果算错了，你就得自己把那块超辣区域吃下去！

输入
第一行四个整数 
n m h w (1≤h≤n≤10，1≤w≤m≤10）。
接下来 n 行，每行 m 个整数，表示火锅每格的辣度值。

输出
最辣区域的总辣度。

样例

输入1
3 6 2 2
1  2  3  4  5  6
7  8  9 10 11 12
13 14 15 16 17 18

输出1
58

输入2
3 6 1 3
1  2  3  4  5  6
7  8  9 10 11 12
13 14 15 16 17 18

输出2
51*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, h, w;
    scanf("%d %d %d %d", &n, &m, &h, &w);

    int s[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &s[i][j]);
        }
    }

    int max = -10000;

    for (int i = 0; i <= n - h; i++) {
        for (int j = 0; j <= m - w; j++) {
            int temp = 0;

            for (int k = i; k < i + h; k++) {
                for (int l = j; l < j + w; l++) {
                    temp += s[k][l];
                }
            }
            
            if (temp > max) {
                max = temp;
            }
        }
    }

    printf("%d\n", max);
    return 0;
}