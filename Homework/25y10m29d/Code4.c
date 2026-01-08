/**
 * @brief 计算交替级数求和
 * 
 * 问题描述：
 * 计算级数 1/3 - 2/5 + 3/8 - 4/12 + 5/17 ... 前n项的值
 * 
 * 数学规律分析：
 * - 第i项分子：i
 * - 第i项分母：i*(i+1)/2 + 2 = (i²+i+4)/2
 * - 第i项符号：奇数项为正，偶数项为负
 * 
 * 算法复杂度：O(n*m)，其中n为测试用例数，m为每个用例的项数
 * 空间复杂度：O(1)
 * 
 * 优化点：
 * - 使用double类型确保精度
 * - 直接计算分母避免重复运算
 */
#include <stdio.h>

int main() {
    int n;  // 测试用例数
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        double sum = 0.0;  // 累加和
        int terms;  // 项数
        scanf("%d", &terms);

        for (int j = 1; j <= terms; j++) {
            // 计算第j项：j / (j*(j+1)/2 + 2)
            double numerator = j;  // 分子
            double denominator = j * (j + 1) / 2.0 + 2;  // 分母
            double term = numerator / denominator;  // 当前项的值
           
            // 交替加减：奇数项为正，偶数项为负
            if (j % 2 == 0) {
                sum -= term;
            } else {
                sum += term;
            }
        }
        printf("%.4lf\n", sum);
    }
    return 0;
}