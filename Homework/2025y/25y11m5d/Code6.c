/**
 * @brief 计算交错级数和
 * 
 * 问题描述：
 * 计算级数 S = a₁ + a₂ + a₃ + ... + aₙ
 * 其中 aᵢ = ±[1/(1·i) + 1/(2·i) + ... + 1/(i·i)]
 * 符号正负交替
 * 
 * 算法分析：
 * - 外层循环：计算每一项aᵢ
 * - 内层循环：计算aᵢ = Σ(1/(j·i))，j从1到i
 * - 奇数项为正，偶数项为负
 * - 时间复杂度：O(n²)
 * - 空间复杂度：O(1)
 * 
 * 数学特点：
 * 这是一个双重求和的交错级数
 */
#include <stdio.h>

int main() {
    int n;  // 项数
    double sum = 0.0;  // 总和S
    
    scanf("%d", &n);
    
    // 计算前n项
    for (int i = 1; i <= n; i++) {
        double term = 0.0;  // 第i项aᵢ
        
        // 计算 aᵢ = Σ(1/(j·i))，j从1到i
        for (int j = 1; j <= i; j++) {
            term += 1.0 / (j * i);
        }
        
        // 交错符号：奇数项为正，偶数项为负
        if (i % 2 == 1) {
            sum += term;
        } else {
            sum -= term;
        }
    }
    
    printf("%.4f\n", sum);
    return 0;
}