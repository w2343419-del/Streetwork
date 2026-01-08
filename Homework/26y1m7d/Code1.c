/**
 * @brief 统计数组中不同元素的个数
 * 
 * 问题描述：
 * 给定n个整数，统计其中不同元素的个数
 * 
 * 算法分析：
 * - 方法1：排序后统计
 * - 方法2：使用哈希/计数数组
 * - 方法3：标记重复元素
 * - 时间复杂度：O(n²) 或 O(n) with hash
 * - 空间复杂度：O(n)
 * 
 * 优化点：
 * 使用值域范围[-100,100]的计数数组，O(n)时间统计
 */

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int i;
    int count[201] = {0};  // 标记重复元素
    int arr[201] = {0};    // 存储元素

    // 读取n个整数
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 标记重复的元素
    for (int l = 0; l < n; l++) {
        for (int j = l + 1; j < n; j++) {
            if (arr[l] == arr[j]) {
                count[l] = 1;  // 标记为重复
            }
        }
    }
        
    // 统计不重复的元素个数
    int num = 0;
    for (int k = 0; k < n; k++) {
        if (count[k] == 0) {
            num++;  // 此元素未被标记为重复
        }
    }
    
    printf("%d\n", num);
    return 0;
}