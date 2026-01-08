/**
 * @brief 判断三角形是否为直角三角形
 * 
 * 算法思路：
 * 1. 使用勾股定理：a² + b² = c²（c为最长边）
 * 2. 使用整数平方而非浮点pow()，避免精度问题
 * 3. 先验证三角形有效性（三边都为正，任意两边之和>第三边）
 * 4. 找出最大边，验证其平方是否等于其他两边平方和
 * 
 * 时间复杂度：O(n)，n为测试用例数
 * 空间复杂度：O(1)
 * 
 * 优化点：
 * - 用整数乘法替代pow()，避免浮点数精度问题
 * - 简化最大边查找逻辑，提高代码可读性
 */

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        
        // 验证三角形有效性
        if (a <= 0 || b <= 0 || c <= 0) {
            printf("No\n");
            continue;
        }
        if (a + b <= c || a + c <= b || b + c <= a) {
            printf("No\n");
            continue;
        }
        
        // 找出最大边和其他两边
        long long max_side, side1, side2;
        if (a >= b && a >= c) {
            max_side = a; side1 = b; side2 = c;
        } else if (b >= a && b >= c) {
            max_side = b; side1 = a; side2 = c;
        } else {
            max_side = c; side1 = a; side2 = b;
        }
        
        // 使用勾股定理验证（a² + b² = c²）
        if (max_side * max_side == side1 * side1 + side2 * side2) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}