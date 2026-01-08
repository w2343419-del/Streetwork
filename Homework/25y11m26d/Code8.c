/**
 * @brief Z字形矩阵填充
 * 
 * 问题描述：
 * 按Z字形路径填充m×n矩阵，数字从1到m×n依次填入
 * 
 * 算法分析：
 * - 使用方向控制：对角线交替向右上和左下移动
 * - 边界处理：触及边界时改变移动方向
 * - 奇偶判断：根据(row+col)的奇偶性决定移动方向
 *   * 偶数：优先向右上移动
 *   * 奇数：优先向左下移动
 * 
 * 时间复杂度：O(m×n)
 * 空间复杂度：O(m×n)
 * 
 * 优化点：
 * - 使用模拟法直接生成，避免复杂的数学计算
 * - 边界判断清晰，逻辑简洁
 */
/*Zig-Zag Matrix*/
#include <stdio.h>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int matrix[100][100];
    int row = 0, col = 0;
    
    for (int num = 1; num <= m * n; num++) {
        matrix[row][col] = num;
        
        if (num == m * n) {
            break;
        }
        
        if ((row + col) % 2 == 0) {
            if (col == n - 1) {
                row++;
            } else if (row == 0) {
                col++;
            } else {
                row--;
                col++;
            }
        } else {
            if (row == m - 1) {
                col++;
            } else if (col == 0) {
                row++;
            } else {
                row++;
                col--;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}