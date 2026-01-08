/**
 * @brief 改进的斐波那契数列
 * \n * 定义：Fn = 2*F(n-1) + 3*F(n-2) + 5*F(n-3)，F1=F2=F3=1
 * \n * 算法思路：
 * 1. 预计算所有可能的值（n≤30）
 * 2. 对每个查询直接返回预计算结果
 * 3. 使用动态规划，时间复杂度O(30) + O(q)，空间O(30)\n * 优化点：
 * - 预计算避免重复运算
 * - 直接下标访问O(1)返回结果
 * \n * 时间复杂度：O(30 + q) = O(q) - q为查询数
 * 空间复杂度：O(30) = O(1)
 */

#include <stdio.h>

int main() {
    int n, index;
    long long fib[31];
    
    // 初始化
    fib[1] = 1;
    fib[2] = 1;
    fib[3] = 1;
    
    // 预计算所有值
    for (int i = 4; i <= 30; i++) {
        fib[i] = 2 * fib[i - 1] + 3 * fib[i - 2] + 5 * fib[i - 3];
    }
    
    // 处理查询
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &index);
        printf("%lld\n", fib[index]);
    }
    
    return 0;
}
