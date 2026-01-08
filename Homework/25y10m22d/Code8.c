/**
 * @brief 计算整数的平方根
 * 
 * 算法思路：
 * 1. 如果m < 0，无平方根，输出ERROR
 * 2. 否则使用sqrt函数计算平方根
 * 3. 格式化输出2位小数
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        
        if (m < 0) {
            // 负数无平方根
            printf("ERROR\n");
        } else {
            // 计算平方根并保留2位小数
            double res = sqrt(m);
            printf("%.2lf\n", res);
        }
    }
    
    return 0;
}
