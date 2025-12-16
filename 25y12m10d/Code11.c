/*小明需要一个程序来自动判定两个图像是否来自于同一幅图像。
已知两个图像A和B的大小都是m∗n，用二进制矩阵来表示，
0表示图像的背景，
1表示图像中的前景物体。
小明的方法是把矩阵A的元素往右往下循环移动后和矩阵B进行比对。
如果一致则表示比对成功，输出移动的最小步数，如果失败则输出No。

注意：往右循环移动一步指将矩阵的列依次右移一格，最右列移动到最左列。
往下循环移动一步指将矩阵的列依次下移一格，最下列移动到最上列。
示例：

  A       B
1 1 0	0 0 0
0 1 0	0 1 1
0 0 0	0 0 1
那么将矩阵A往右移动1步，再往下移动1步，发现此时和矩阵B能够匹配，所以认为A和B来自于同一幅图像，输出步数2。

  A     右移1步  下移1步
1 1 0    0 1 1    0 0 0
0 1 0 => 0 0 1 => 0 1 1
0 0 0    0 0 0    0 0 1

输入
第一行输入 m,n (3≤m,n≤10)，表示输入的图像的行和列的数量。
随后输入2个 m∗n 的二维数组代表图像A和B。

输出
如果能够成功匹配，则输出最小移动步数，如果不能匹配则输出No。

样例
输入
3 3
1 1 0
0 1 0
0 0 0
0 0 0
0 1 1
0 0 1
输出

2*/

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int a[10][10], b[10][10];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    int min_steps = -1;
    int found = 0;

    for (int r = 0; r < n; r++) {
        for (int d = 0; d < m; d++) {
            int match = 1;
            
            for (int i = 0; i < m && match; i++) {
                for (int j = 0; j < n; j++) {
                    int orig_i = (i - d + m) % m;
                    int orig_j = (j - r + n) % n;
                    if (a[orig_i][orig_j] != b[i][j]) {
                        match = 0;
                        break;
                    }
                }
            }
            
            if (match == 1) {
                found = 1;
                int steps = r + d;
                if (min_steps == -1 || steps < min_steps) {
                    min_steps = steps;
                }
            }
        }
    }

    if (found) {
        printf("%d\n", min_steps);
    } else {
        printf("No\n");
    }

    return 0;
}
