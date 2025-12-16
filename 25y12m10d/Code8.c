/*听说矩阵也会流眼泪？
当你剥开它的时候，就像剥洋葱——这一圈的数字们就集体“哭”一次，哗啦哗啦掉下一堆数值。
现在给你一把编号为 k 的“小刀”，
请你精准地切下矩阵的由外向内的第 k 层洋葱皮（最外层为第 1 层，向内每递进一层编号加 1 ），
然后把它们掉下来的数值统统加起来，告诉我们这圈“眼泪”到底有多重！

输入
第一行：m 、n 和 k ，用空格分隔。
告诉你这颗洋葱有 m 行 n 列（ 1≤m,n≤15 ）。
k 是一个正整数，表示你要切的层数。
接下来 m 行：每行 n 个整数，就是洋葱细胞里蕴含的眼泪值。

输出
一个整数：第 k 层洋葱皮掉下来的眼泪总和。
（如果 k 太大，请输出 0，表示“这一层没哭”。）

样例

输入1
5 6 3
1 1 1 1 1 1
1 2 2 2 2 1
1 2 3 3 2 1
1 2 2 2 2 1
1 1 1 1 1 1

输出1
6

输入2
5 6 5
1 1 1 1 1 1
1 2 2 2 2 1
1 2 3 3 2 1
1 2 2 2 2 1
1 1 1 1 1 1

输出2
0*/

#include <stdio.h>

int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);

    int matrix[m][n];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (k > (m + 1) / 2 || k > (n + 1) / 2) {
        printf("0\n");
    } else {
        int sum = 0;
        k = k - 1;


        for (int j = k; j < n - k; j++) {
            sum += matrix[k][j];
        }

        for (int i = k + 1; i < m - k; i++) {
            sum += matrix[i][n - k - 1];
        }

        if (m - k - 1 > k) {
            for (int j = n - k - 2; j >= k; j--) {
                sum += matrix[m - k - 1][j];
            }
        }

        if (n - k - 1 > k) {
            for (int i = m - k - 2; i > k; i--) {
                sum += matrix[i][k];
            }
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}
