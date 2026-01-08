/**
 * @brief 计算两数之间所有奇数的和
 * 
 * 算法思路：
 * 1. 对m和n进行大小比较，确定范围
 * 2. 遍历该范围内的所有数，累加奇数
 * 3. 输出结果
 * 
 * 优化点：
 * - 使用数学公式计算奇数和（更高效）
 *   对于[min, max]的奇数，如果最小奇数为first，最大奇数为last
 *   则奇数和 = (count * (first + last)) / 2，其中count为奇数个数
 * 
 * 时间复杂度：O(n) 或 O(1)（如果使用公式）
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    
    for (int i = 0; i < x; i++) {
        int m, n;
        scanf("%d %d", &m, &n);
        
        // 确定范围
        int min = (m < n) ? m : n;
        int max = (m > n) ? m : n;
        
        // 找出第一个奇数
        int first_odd = (min % 2 == 1) ? min : min + 1;
        
        // 找出最后一个奇数
        int last_odd = (max % 2 == 1) ? max : max - 1;
        
        // 如果没有奇数
        if (first_odd > last_odd) {
            printf("0\n");
            continue;
        }
        
        // 使用等差数列求和公式
        int count = (last_odd - first_odd) / 2 + 1;
        long long sum = (long long)count * (first_odd + last_odd) / 2;
        
        printf("%lld\n", sum);
    }
    
    return 0;
}


