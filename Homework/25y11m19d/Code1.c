/**
 * @brief 完全数判断
 * 
 * 完全数：一个数的所有真因子（除自身外的所有正因子）之和等于该数
 * 例：6 = 1 + 2 + 3，28 = 1 + 2 + 4 + 7 + 14
 * 
 * 算法思路：
 * 1. 初始化sum=1（因为1总是因子）
 * 2. 从2到√n枚举所有可能的因子i
 * 3. 若i是因子，则同时加入i和n/i
 * 4. 特殊处理完全平方数的情况
 * 5. 比较sum和n
 * 
 * 时间复杂度：O(√n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 1) {
        printf("0\n");
        return 0;
    }
    
    int sum = 1;  // 1是任何数的因子
    
    // 枚举所有可能的因子
    for (int i = 2; i * i < n; i++) {
        if (n % i == 0) {
            sum += i + n / i;
        }
    }
    
    // 处理完全平方数
    int sqrt_n = 1;
    while (sqrt_n * sqrt_n < n) sqrt_n++;
    if (sqrt_n * sqrt_n == n) {
        sum += sqrt_n;
    }
    
    if (sum == n) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}

