/**
 * @brief 哥德巴赫猜想 - 偶数分解为两个奇质数之和
 * 
 * 算法思路：
 * 1. 验证输入：必须为大于6的偶数
 * 2. 枚举所有奇数i，检查i和(n-i)是否都是质数
 * 3. 只遍历到n/2，避免重复输出
 * 
 * 优化点：
 * - 使用质数检测函数，避免重复代码
 * - 只检查奇数（偶数（除2外）不是质数）
 * - 早期返回，避免无用输出
 * 
 * 时间复杂度：O(n/2 * √n) = O(n√n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>
#include <math.h>

// 检查是否为质数
int is_prime(int num) {
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    
    for (int i = 3; i <= (int)sqrt(num); i += 2) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;
    
    while (scanf("%d", &n) != EOF) {
        // 验证输入
        if (n <= 6 || n % 2 != 0) {
            printf("ERROR\n");
            continue;
        }
        
        int found = 0;
        
        // 枚举所有奇数i
        for (int i = 3; i <= n / 2; i += 2) {
            if (is_prime(i) && is_prime(n - i)) {
                printf("%d %d\n", i, n - i);
                found = 1;
            }
        }
        
        // 如果没有找到分解
        if (!found) {
            printf("ERROR\n");
        }
    }
    
    return 0;
}
