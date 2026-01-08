/**
 * @brief 整数的2的幂次表示
 * 
 * 算法思路：
 * 使用位运算检查每一位是否为1：
 * 1. 从高位（第31位）到低位（第0位）扫描
 * 2. 若该位为1，说明该位对应的2^i是分解的一部分
 * 3. 按幂次降序输出
 * 
 * 例：9 = 1001(二进制) = 2^3 + 2^0
 * 
 * 时间复杂度：O(32) = O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    printf("%d=", n);
    
    int first = 1;
    
    // 从高位到低位扫描
    for (int i = 31; i >= 0; i--) {
        if (n & (1 << i)) {
            if (!first) {
                printf("+");
            }
            first = 0;
            
            printf("2^%d", i);
        }
    }
    
    printf("\n");
    
    return 0;
}
