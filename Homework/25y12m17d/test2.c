/**
 * @brief 计算四个整数绝对值之和
 * 
 * 算法思路：
 * 1. 读取4个整数
 * 2. 对每个数取绝对值
 * 3. 求和并输出
 * 
 * 优化点：可使用abs()函数简化
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // 取绝对值并求和
    int sum = abs(a) + abs(b) + abs(c) + abs(d);
    
    printf("%d\n", sum);
    
    return 0;
}
