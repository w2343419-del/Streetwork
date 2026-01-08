/**
 * @brief 判断点是否严格位于圆内（不包括边界）
 * 
 * 算法思路：
 * 使用距离公式：d² = (cx - px)² + (cy - py)²
 * 若 d² < r²，则点在圆内
 * 
 * 优化点：避免使用sqrt，直接比较平方
 * 使用long long避免整数溢出
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int cx, cy, r, px, py;
    scanf("%d %d %d %d %d", &cx, &cy, &r, &px, &py);
    
    // 计算距离平方（使用long long避免溢出）
    long long dx = cx - px;
    long long dy = cy - py;
    long long dist_sq = dx * dx + dy * dy;
    long long r_sq = (long long)r * r;
    
    if (dist_sq < r_sq) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}
