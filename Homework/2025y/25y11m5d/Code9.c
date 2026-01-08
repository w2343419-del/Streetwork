/**
 * @brief 计算最大公约数（GCD）
 * 
 * 问题描述：
 * 输入两个正整数m和n，输出它们的最大公约数
 * 
 * 算法分析：
 * - 方法：欧几里得算法（辗转相除法）
 * - 原理：gcd(a,b) = gcd(b, a%b)，直到b=0
 * - 时间复杂度：O(log min(m,n))
 * - 空间复杂度：O(1)
 * 
 * 数学原理：
 * 欧几里得算法是求最大公约数最经典的算法
 * 例：gcd(48,18) → gcd(18,12) → gcd(12,6) → gcd(6,0) = 6
 */
#include <stdio.h>

int main() {
    int t;  // 测试用例数
    int m, n;  // 两个待求GCD的数
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; i++) {
        scanf("%d %d", &m, &n);
        
        int a = m, b = n;
        
        // 欧几里得算法（辗转相除法）
        while (b != 0) {
            int temp = b;
            b = a % b;  // 用余数替换b
            a = temp;  // 用原来的b替换a
        }
        
        // 当b=0时，a就是最大公约数
        printf("%d\n", a);
    }
    
    return 0;
}