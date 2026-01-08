/**
 * @brief 球的组合计数
 * 
 * 问题描述：
 * 有黑球3个、白球3个、蓝球6个，随机抓n个，问有多少种颜色数量组合方案
 * 
 * 算法分析：
 * - 枚举黑球数i(0..min(3,n))和白球数j(0..min(3,n-i))
 * - 蓝球数k由约束k = n - i - j确定，需满足0 ≤ k ≤ 6
 * - 对每个合法(i,j,k)计数
 * 
 * 时间复杂度：O(常数) - i、j的范围都很小
 * 空间复杂度：O(1)
 * 
 * 优化点：
 * - 利用数量上限剪枝，减少无效枚举
 */
//黑球3个，白球3个，蓝球6个，抓n个，有几种可能
#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    
    for (int t = 0; t < m; t++) {
        int n;
        scanf("%d", &n);
        
        int count = 0;
        int i, j, k;
        
        for (i = 0; i <= 3 && i <= n; i++) {      
            for (j = 0; j <= 3 && j <= n - i; j++) {    
                k = n - i - j;                          
                if (k >= 0 && k <= 6) {            
                    count++;
                }
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}