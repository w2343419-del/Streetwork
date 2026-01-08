/**
 * @brief 最辣区域查找（最大矩形和）
 * 
 * 算法思路：
 * 1. 读取n×m的辣度矩阵
 * 2. 枚举所有h×w的子矩形
 * 3. 计算每个子矩形的总辣度
 * 4. 输出最大值
 * 
 * 优化点：
 * - 使用二维前缀和可将复杂度从O(nmhw)降至O(nm)
 * 
 * 时间复杂度：O((n-h+1)(m-w+1)hw) = O(nmhw)
 * 空间复杂度：O(nm)
 */

#include <stdio.h>

int main() {
    int n, m, h, w;
    scanf("%d %d %d %d", &n, &m, &h, &w);
    
    int grid[n][m];
    
    // 读取辣度矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }
    
    int max_spicy = -2147483648;
    
    // 枚举所有可能的h×w矩形的左上角
    for (int i = 0; i <= n - h; i++) {
        for (int j = 0; j <= m - w; j++) {
            int sum = 0;
            
            // 计算该矩形的总辣度
            for (int di = 0; di < h; di++) {
                for (int dj = 0; dj < w; dj++) {
                    sum += grid[i + di][j + dj];
                }
            }
            
            if (sum > max_spicy) {
                max_spicy = sum;
            }
        }
    }
    
    printf("%d\n", max_spicy);
    
    return 0;
}
