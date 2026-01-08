/**
 * @brief 交错级数求和
 * 
 * 计算：1 - 1/2 + 1/3 - 1/4 + ... + (-1)^(n+1) * 1/n
 * 
 * 算法思路：
 * 奇数项为正，偶数项为负
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    
    double sum = 0.0;
    
    for (long long i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            sum += 1.0 / i;
        } else {
            sum -= 1.0 / i;
        }
    }
    
    printf("%.4f\n", sum);
    
    return 0;
}
