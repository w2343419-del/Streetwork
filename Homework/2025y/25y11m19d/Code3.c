/**
 * @brief 销售量折点计算
 * 
 * 折点定义：
 * - 极大值：前值 < 当前值 > 后值
 * - 极小值：前值 > 当前值 < 后值
 * 
 * 算法思路：
 * 1. 遍历第1到n-2位置（中间的元素）
 * 2. 检查是否为极大值或极小值
 * 3. 计数折点个数
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int count = 0;
    
    // 检查中间的每个元素
    for (int i = 1; i < n - 1; i++) {
        // 极大值：a[i-1] < a[i] > a[i+1]
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            count++;
        }
        // 极小值：a[i-1] > a[i] < a[i+1]
        else if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
