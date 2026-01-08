/**
 * @brief 分段函数计算
 * 
 * 算法思路：
 * 根据x的值分段计算：
 * - x < 0：y = x²
 * - 0 ≤ x ≤ 10：y = 2x + 3
 * - x > 10：y = 3x - 7
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    double x, y;
    scanf("%lf", &x);
    
    if (x < 0) {
        y = x * x;
    } else if (x <= 10) {
        y = 2 * x + 3;
    } else {
        y = 3 * x - 7;
    }
    
    printf("%.2lf\n", y);
    
    return 0;
}
