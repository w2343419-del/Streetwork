/**
 * @brief 计算正整数的位数
 * 
 * 问题描述：
 * 判断一个正整数在十进制下有多少位
 * 
 * 算法分析：
 * - 方法1（本代码）：循环除以10，计数
 * - 方法2：使用对数 floor(log10(n)) + 1
 * - 时间复杂度：O(log₁₀n)
 * - 空间复杂度：O(1)
 * 
 * 数学原理：
 * 一个数n的位数 = ⌊log₁₀n⌋ + 1
 */
#include <stdio.h>

int main() {
    int n;  // 测试用例数
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int num;  // 待判断的数
        scanf("%d", &num);

        int digits = 0;  // 位数计数
        int temp = num;
        
        // 循环除以10，直到变成0
        while (temp > 0) {
            temp /= 10;
            digits++;
        }
        
        printf("%d\n", digits);
    }
    
    return 0;
}