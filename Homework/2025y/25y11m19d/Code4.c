/**
 * @brief 两数组的距离（最大差的绝对值）
 * 
 * 算法思路：
 * 1. 分别找出两个数组的最大值和最小值
 * 2. 两个数组距离 = max(max1 - min2, max2 - min1)
 * 3. 这样可以找到任意两元素差的最大值
 * 
 * 优化点：
 * - 合并函数，避免代码重复
 * - 直接计算，无需存储所有差值\n * 时间复杂度：O(m + n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int m, max1 = -999999, min1 = 999999;
    scanf("%d", &m);
    
    for (int i = 0; i < m; i++) {
        int val;
        scanf("%d", &val);
        if (val > max1) max1 = val;
        if (val < min1) min1 = val;
    }
    
    int n, max2 = -999999, min2 = 999999;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        if (val > max2) max2 = val;
        if (val < min2) min2 = val;
    }
    
    // 距离 = max(|max1-min2|, |max2-min1|)
    int dist1 = max1 - min2;
    int dist2 = max2 - min1;
    int distance = (dist1 > dist2) ? dist1 : dist2;
    
    printf("%d\n", distance);
    
    return 0;
}
