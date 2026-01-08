/**
 * @brief 计算三个整数的最大值和最小值的差
 * 
 * 算法思路：
 * 1. 先比较前两个数确定初始的max和min
 * 2. 再将第三个数与max和min比较更新
 * 3. 计算差值并输出
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    
    // 初始化max和min
    int max = (a > b) ? a : b;
    int min = (a > b) ? b : a;
    
    // 更新max
    if (c > max) {
        max = c;
    }
    
    // 更新min
    if (c < min) {
        min = c;
    }
    
    // 输出差值
    printf("%d\n", max - min);
    
    return 0;
}
