/**
 * @brief 使用海伦公式计算三角形面积
 * 
 * 问题描述：
 * 利用海伦公式求三角形面积：S = √[p(p-a)(p-b)(p-c)]
 * 其中 p = (a+b+c)/2
 * 
 * 算法分析：
 * - 前提：需先判断三条边能否构成三角形
 * - 三角形成立条件：任意两边之和大于第三边
 * - 海伦公式：先计算半周长p，再代入公式计算
 * - 时间复杂度：O(1)
 * - 空间复杂度：O(1)
 * 
 * 数学背景：
 * 海伦公式（Heron's Formula）由古希腊数学家海伦发现
 * 优点：仅需边长即可计算面积，无需角度或高
 */
#include <stdio.h>
#include <math.h>

int main() {
    int n;  // 测试用例数
    int a, b, c;  // 三角形三条边
    double p, area;  // p为半周长，area为面积
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        
        // 判断能否构成三角形：三边为正，且任意两边之和大于第三边
        if (a > 0 && b > 0 && c > 0 && 
            a + b > c && b + c > a && c + a > b) {
            // 计算半周长
            p = (a + b + c) / 2.0;
            
            // 海伦公式：S = √[p(p-a)(p-b)(p-c)]
            area = sqrt(p * (p - a) * (p - b) * (p - c));
            
            printf("%.2lf\n", area);
        } else {
            printf("error\n");
        }
    }
    
    return 0;
}