/**
 * @brief 打印菱形图案
 * 
 * 问题描述：
 * 输入奇数n，打印由*组成的菱形
 * 第一行1个*，递增到n个*，再递减到1个*
 * 
 * 算法分析：
 * - 分两部分：上半部分递增，下半部分递减
 * - 每行先打印空格（居中），再打印*
 * - 空格数：(n - 当前行星数) / 2
 * - 时间复杂度：O(n²)
 * - 空间复杂度：O(1)
 * 
 * 图案规律：
 * 第i行（i为奇数1,3,5...）：(n-i)/2个空格 + i个星号
 */
#include <stdio.h>

int main() {
    int test_count;  // 测试用例数
    int n;  // 菱形边长
    
    scanf("%d", &test_count);
    
    for (int t = 1; t <= test_count; t++) {
        scanf("%d", &n);
        
        // 检查是否为奇数
        if (n % 2 == 0) {
            printf("error\n");
            continue;
        }
        
        printf("print\n");
        
        // 上半部分：从1个*递增到n个*
        for (int i = 1; i <= n; i += 2) {
            // 打印前导空格（居中对齐）
            for (int j = 1; j <= (n - i) / 2; j++) {
                printf(" ");
            }
            // 打印*
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
        
        // 下半部分：从n-2个*递减到1个*
        for (int i = n - 2; i >= 1; i -= 2) {
            // 打印前导空格
            for (int j = 1; j <= (n - i) / 2; j++) {
                printf(" ");
            }
            // 打印*
            for (int j = 1; j <= i; j++) {
                printf("*");
            }
            printf("\n");
        }
    }
    
    return 0;
}