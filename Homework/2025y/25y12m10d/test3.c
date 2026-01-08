/**
 * @brief 二维数组求和函数
 * 
 * 问题描述：
 * 计算二维数组所有元素的总和
 * 
 * 算法分析：
 * - 使用函数传递二维数组（需指定列数）
 * - 双重循环遍历累加
 * 
 * 时间复杂度：O(rows×cols)
 * 空间复杂度：O(1)
 */
#include <stdio.h>

int sum_matrix(int arr[][100], int rows, int cols) {
    int sum = 0;
    // 双重循环遍历所有元素
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += arr[i][j];  // 累加当前元素
        }
    }
    return sum;
}

int main() {
    int matrix[100][100] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    int rows = 3;
    int cols = 4;

    int total = sum_matrix(matrix, rows, cols);
    printf("%d\n", total);

    return 0;
}