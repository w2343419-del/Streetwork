/*2149 年，机动战士用「回旋十字斩」雷达扫描战场：
以自身为中心，划出一个「十字」——上下左右各延伸 1 格，把这五格的能量相加，得到能量和 s。
若 s > 爆裂阈值 t，则该点标记为爆裂点，可发动必杀技。

你的任务：扫描整个 m×n 战场，统计并输出爆裂点的个数。

注意：战场边缘不完整的十字区域也需要扫描！！！

输入
第一行：三个整数 m 、n、t，（1≤m,n≤20）
接下来 m 行：每行 n 个整数，表示战场能量矩阵，中间用空格分隔。

输出
爆裂点总数。

样例
输入1
3 5 10
1 1 1 1 1
2 5 1 5 1
1 1 0 0 2
输出1
1

输入2
3 5 10
1 5 1 1 1
2 5 1 5 1
1 1 0 0 2
输出2
3*/

#include <stdio.h>

int main() {
    int m, n, t;
    scanf("%d %d %d", &m, &n, &t);
    int a[20][20];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = a[i][j];
            if (i - 1 >= 0) sum += a[i - 1][j];
            if (i + 1 < m) sum += a[i + 1][j];
            if (j - 1 >= 0) sum += a[i][j - 1];
            if (j + 1 < n) sum += a[i][j + 1];

            if (sum > t) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
