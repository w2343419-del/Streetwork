/**
 * @brief 奇偶位数字交换
 * 
 * 算法思路：
 * 1. 将整数转换为字符串处理
 * 2. 保留符号位，从数字位开始交换
 * 3. 每次交换两个相邻的数字（第1和2位、第3和4位...）
 * 4. 转换回整数并输出
 * 
 * 优化点：
 * - 使用字符串处理更清晰
 * - 正确处理负数符号
 * 
 * 时间复杂度：O(log n) - n的位数
 * 空间复杂度：O(log n)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    char s[33];
    sprintf(s, "%d", n);

    // 确定数字部分的起始位置（跳过负号）
    int start_index = (s[0] == '-') ? 1 : 0;
    int len = strlen(s);
    
    // 交换奇偶位的数字
    for (int i = start_index; i < len - 1; i += 2) {
        char temp = s[i];
        s[i] = s[i + 1];
        s[i + 1] = temp;
    }

    // 转换回整数
    int result = atoi(s);
    printf("%d\n", result);
    
    return 0;
}
