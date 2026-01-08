/**
 * @brief 计算偶数倒数序列和：1/2 + 1/4 + ... + 1/n
 * 
 * 算法思路：
 * 1. 对于每个测试用例，初始化求和器为0
 * 2. 直接遍历偶数2,4,6,...,n（步长为2）
 * 3. 累加1.0/j到和
 * 4. 输出结果保留4位小数
 * 
 * 时间复杂度：O(m*n)，m为测试用例数
 * 空间复杂度：O(1)
 * 
 * 优化点：
 * - 直接遍历偶数，避免条件判断
 */

#include <stdio.h>
int main() {
    int m;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int n;
        scanf("%d", &n);
        
        double sum = 0.0;
        // 直接遍历偶数，步长为2
        for (int j = 2; j <= n; j += 2) {
            sum += 1.0 / j;
        }
        
        printf("%.4lf\n", sum);
    }
    
    return 0;
}