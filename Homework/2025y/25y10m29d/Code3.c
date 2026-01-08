/**
 * @brief 计算级数和：1/2 + 2/3 + 3/4 + ... + n/(n+1)
 * 
 * 算法思路：
 * 1. 第j项 = j/(j+1)
 * 2. 累加所有项得到总和
 * 3. 输出结果保留4位小数
 * 
 * 数学性质：
 * - 每一项 j/(j+1) = 1 - 1/(j+1)
 * - 前n项和约接近n（当n很大时）
 * 
 * 时间复杂度：O(m*n)，m为测试用例数
 * 空间复杂度：O(1)
 */

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        
        double sum = 0.0;
        // 累加 j/(j+1)
        for (int j = 1; j <= a; j++) {
            sum += (double)j / (j + 1.0);
        }
        
        printf("%.4lf\n", sum);
    }
    
    return 0;
}