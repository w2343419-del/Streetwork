/**
 * @brief 找出缺失的数字
 * 
 * 算法思路：
 * 1. 使用布尔数组标记出现过的数字
 * 2. 查找1到n中没有被标记的数字
 * 
 * 优化点：
 * - 直接遍历标记，避免计算和的方式（更清晰）
 * - 时间复杂度O(n)，空间复杂度O(n)
 */

#include <stdio.h>
#include <string.h>

int main() {
    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int seen[1002] = {0};
        int num, count = 0;

        // 标记出现过的数字
        while (1) {
            scanf("%d", &num);
            if (num == 0) break;
            seen[num] = 1;
            count++;
        }

        // n为count+1（因为缺少一个数字）
        int n = count + 1;
        
        // 查找缺失的数字
        for (int j = 1; j <= n; j++) {
            if (!seen[j]) {
                printf("%d\n", j);
                break;
            }
        }
    }
    
    return 0;
}
