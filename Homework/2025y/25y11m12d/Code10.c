/**
 * @brief 阶乘和的模运算
 * \n * 定义：f(n) = (Σ(i=1 to n) i!) % 1000000\n * 算法思路：
 * 1. 预计算1到1000000的所有阶乘（模1000000）
 * 2. 前缀和数组存储累积和
 * 3. 对每个查询直接返回sum[n]\n * 优化点：
 * - 使用模运算避免溢出：(a*b) % m = ((a%m) * (b%m)) % m
 * - 前缀和避免重复计算
 * - 一次预处理，多次O(1)查询\n * 时间复杂度：O(1000000 + k)
 * 空间复杂度：O(1000000) - 两个数组存储阶乘和前缀和
 */

#include <stdio.h>

#define MOD 1000000

int main() {
    int k, n;
    
    // 使用static分配，避免栈溢出
    static long long fact[1000001];
    static long long sum[1000001];
    
    // 初始化基础值
    fact[0] = 1;
    fact[1] = 1;
    sum[1] = 1;
    
    // 预计算所有阶乘和累积和
    for (int i = 2; i <= 1000000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        sum[i] = (sum[i - 1] + fact[i]) % MOD;
    }
    
    // 处理查询
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        printf("%lld\n", sum[n]);
    }
    
    return 0;
}
