/**
 * @brief 判断是否为直角三角形
 * 
 * 算法思路：
 * 1. 验证三边能构成三角形（三边不等式）
 * 2. 找出三边的最大值、中间值、最小值
 * 3. 验证勾股定理：a² + b² = c²
 * 
 * 优化点：
 * - 使用简单的排序逻辑替代复杂的if-else
 * - 用乘法替代pow函数（整数运算更快）
 * - 避免浮点数比较
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

// 交换两个整数
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int sides[3];
        scanf("%d %d %d", &sides[0], &sides[1], &sides[2]);
        
        // 检查边长是否有效
        if (sides[0] <= 0 || sides[1] <= 0 || sides[2] <= 0) {
            printf("No\n");
            continue;
        }
        
        // 检查三边不等式
        if (sides[0] + sides[1] <= sides[2] || 
            sides[0] + sides[2] <= sides[1] || 
            sides[1] + sides[2] <= sides[0]) {
            printf("No\n");
            continue;
        }
        
        // 简单排序：确保 sides[0] >= sides[1] >= sides[2]
        if (sides[0] < sides[1]) swap(&sides[0], &sides[1]);
        if (sides[0] < sides[2]) swap(&sides[0], &sides[2]);
        if (sides[1] < sides[2]) swap(&sides[1], &sides[2]);
        
        // 勾股定理验证（避免浮点运算，使用整数乘法）
        long long max_sq = (long long)sides[0] * sides[0];
        long long sum_sq = (long long)sides[1] * sides[1] + (long long)sides[2] * sides[2];
        
        if (max_sq == sum_sq) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}