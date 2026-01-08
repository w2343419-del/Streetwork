/**
 * @brief 质因数分解
 * 
 * 算法思路：
 * 1. 特殊处理1的情况
 * 2. 从2开始逐个尝试质因数
 * 3. 对每个质因数，反复整除直到不能整除
 * 4. 格式化输出，用*分隔因子
 * 
 * 优化点：
 * - 跳过偶数（除了2），从3开始步长为2
 * - 只要temp > 1就继续循环
 * - 避免使用sqrt，直接用temp > 1判断
 * 
 * 时间复杂度：O(√num)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // 特殊处理1
        if (num == 1) {
            printf("1\n");
            continue;
        }
        
        int first = 1;
        int factor = 2;
        int temp = num;
        
        // 质因数分解
        while (temp > 1) {
            // 反复整除该因数
            while (temp % factor == 0) {
                if (!first) {
                    printf("*");
                }
                printf("%d", factor);
                first = 0;
                temp /= factor;
            }
            
            // 下一个可能的质因数
            factor = (factor == 2) ? 3 : factor + 2;
            
            // 优化：如果factor²超过temp，则temp本身是质数
            if (factor * factor > temp && temp > 1) {
                if (!first) {
                    printf("*");
                }
                printf("%d", temp);
                temp = 1;
            }
        }
        
        printf("\n");
    }
    
    return 0;
}
