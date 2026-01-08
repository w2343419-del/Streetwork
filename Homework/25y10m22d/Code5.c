/**
 * @brief 判断两个圆的位置关系
 * 
 * 算法思路：
 * 根据圆心距d与半径r1、r2的关系判断：
 * - d > r1+r2：相离(0)
 * - d = r1+r2：外切(1)
 * - |r1-r2| < d < r1+r2：相交(2)
 * - d = |r1-r2|：内切(3)
 * - d < |r1-r2|：内含(4)
 * - d = 0 且 r1 ≠ r2：同心(5)
 * 
 * 优化点：避免重复计算，提前计算d²、(r1+r2)²、(r1-r2)²
 * 使用long long避免整数溢出
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int x1, y1, r1, x2, y2, r2;
    scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
    
    // 计算圆心距离平方
    long long dx = x1 - x2;
    long long dy = y1 - y2;
    long long d_sq = dx * dx + dy * dy;
    
    // 计算相关的平方值
    long long sum_r_sq = (long long)(r1 + r2) * (r1 + r2);
    long long diff_r_sq = (long long)(r1 - r2) * (r1 - r2);
    
    int relation;
    
    if (d_sq > sum_r_sq) {
        relation = 0;  // 相离
    } else if (d_sq == sum_r_sq) {
        relation = 1;  // 外切
    } else if (d_sq > diff_r_sq) {
        relation = 2;  // 相交
    } else if (d_sq == diff_r_sq) {
        relation = 3;  // 内切
    } else if (d_sq > 0) {
        relation = 4;  // 内含
    } else {
        relation = 5;  // 同心
    }
    
    printf("%d\n", relation);
    
    return 0;
}
