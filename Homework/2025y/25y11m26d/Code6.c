/**
 * @brief 矩阵中的循环移动模拟
 * 
 * 问题描述：
 * N×M矩阵，每个位置有方向指示(U/D/L/R)
 * 从给定位置出发，按方向移动step次，求最终位置
 * 
 * 算法分析：
 * - 方法1：直接模拟step次移动
 * - 方法2：检测循环，利用循环节优化
 * - 边界处理：到达边界时循环到对侧
 * - 时间复杂度：O(step) 或 O(N×M) 使用循环检测
 * - 空间复杂度：O(1)
 * 
 * 优化思路：
 * 检测循环路径，如果进入循环则利用模运算快速计算
 */

#include <stdio.h>
int main() {
    int n, m;
    char s[51][51]; 
    scanf("%d %d", &n, &m);

    int c;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &s[i][j]);
        }
        while (1) {
            c = getchar();
            if (c == EOF || c == '\n') {
                break;
            }
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int x0, y0, step;
        scanf("%d %d %d", &x0, &y0, &step);
        int dx = x0, dy = y0;
        for (int i = 0; i < step; i++) {
            char d = s[dx - 1][dy - 1];            
            switch (d) {
                case 'U': {
                    if (dx == 1) {
                        dx = n;
                    } else {
                        dx = dx - 1;
                    }
                    break;
                }
                case 'D': {
                    if (dx == n) {
                        dx = 1;
                    } else {
                        dx = dx + 1;
                    }
                    break;
                }
                case 'L': {
                    if (dy == 1) {
                        dy = m;
                    } else {
                        dy = dy - 1;
                    }
                    break;
                }
                case 'R': {
                    if (dy == m) {
                        dy = 1;
                    } else {
                        dy = dy + 1;
                    }
                    break;
                }
            }
        }
        printf("%d %d\n", dx, dy);
    }
    return 0;
}