/**
 * @brief 从N个正整数中找出最小的能被3整除的数
 * 
 * 程序从标准输入读取N个正整数，遍历这些数找出其中最小的能被3整除的数。
 * 如果存在能被3整除的数，则输出该最小值；否则输出"Null"。
 * 
 * @param stdin 输入流包含：
 *        - 第一个整数：正整数的个数 N
 *        - 接下来 N 个整数：待处理的正整数
 * 
 * @return 正常完成时返回 EXIT_SUCCESS
 * 
 * @note 时间复杂度: O(N)
 *       空间复杂度: O(1)
 */
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int min_divisible = -1;  // 用 -1 表示未找到能被3整除的数
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // 检查是否能被3整除
        if (num % 3 == 0) {
            if (min_divisible == -1 || num < min_divisible) {
                min_divisible = num;
            }
        }
    }
    
    // 输出结果
    if (min_divisible == -1) {
        printf("Null\n");
    } else {
        printf("%d\n", min_divisible);
    }
    
    return 0;
}