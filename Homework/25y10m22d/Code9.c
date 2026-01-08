/**
 * @brief 判断三角形的类型（锐角/直角/钝角）
 * 
 * 算法思路：
 * 1. 验证三角形的三边不等式
 * 2. 使用勾股定理判断：
 *    - a² = b² + c² → 直角
 *    - a² > b² + c² → 钝角
 *    - a² < b² + c² → 锐角
 * 
 * 优化点：
 * - 提取排序逻辑到函数
 * - 使用三元运算符简化排序
 * - 避免浮点运算，直接比较平方
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

// 简化排序函数
void sort_three(int *a, int *b, int *c) {
    if (*a < *b) { int t = *a; *a = *b; *b = t; }
    if (*a < *c) { int t = *a; *a = *c; *c = t; }
    if (*b < *c) { int t = *b; *b = *c; *c = t; }
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int a, b, c;
        scanf("%d,%d,%d", &a, &b, &c);
        
        // 排序三边，使a为最大值
        sort_three(&a, &b, &c);
        
        // 检查三角形不等式
        if (a >= b + c) {
            printf("illegal\n");
            continue;
        }
        
        // 使用long long避免溢出
        long long a_sq = (long long)a * a;
        long long bc_sq = (long long)b * b + (long long)c * c;
        
        // 根据勾股定理判断
        if (a_sq > bc_sq) {
            printf("obtuse\n");
        } else if (a_sq == bc_sq) {
            printf("right\n");
        } else {
            printf("acute\n");
        }
    }
    
    return 0;
}
