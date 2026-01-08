/**
 * @brief 高精度除法（保留指定小数位数）
 * 
 * 问题描述：
 * 计算a/b的小数形式，精确到小数点后c位
 * 
 * 算法分析：
 * - 整数部分：a/b
 * - 小数部分：模拟手工除法
 *   - 余数×10再除以b得到下一位
 *   - 重复c次得到c位小数
 * - 时间复杂度：O(n×c)
 * - 空间复杂度：O(1)
 * 
 * 实现技巧：
 * 使用长除法思想，每次余数×10再除
 * 避免浮点误差，所有计算用整数完成
 */
#include <stdio.h>

int main() {
    int n;  // 测试用例数
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        int a, b, c;  // a/b，保留c位小数
        scanf("%d %d %d", &a, &b, &c);
        
        // 输出整数部分
        printf("%d.", a / b);
        
        // 计算小数部分（模拟长除法）
        int remainder = a % b;  // 余数
        
        for (int j = 0; j < c; j++) {
            remainder = remainder * 10;  // 余数×10
            int digit = remainder / b;  // 得到当前小数位
            printf("%d", digit);
            remainder = remainder % b;  // 更新余数
        }
        
        printf("\n");
    }
    
    return 0;
}