/**
 * @brief 计算三个整数的立方和
 * 
 * 优化说明：
 * - 避免使用pow函数（pow针对浮点数，对整数效率低且可能有精度问题）
 * - 直接用乘法计算立方：a*a*a
 * - 消除不必要的中间变量
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // 直接计算立方和，避免使用pow函数和中间变量
    // a³ + b³ + c³ = a*a*a + b*b*b + c*c*c
    int sum = a * a * a + b * b * b + c * c * c;
    
    printf("%d\n", sum);
    return 0;
}