/**
 * @brief 统计竖线对外的星号个数
 * 
 * 算法思路：
 * 使用状态机追踪当前是否在竖线对内部：
 * 1. 遇到|时，切换in_pair状态
 * 2. 遇到*且不在对内时，计数+1
 * 3. 其他字符忽略
 * \n * 优化点：
 * - 单遍扫描，时间复杂度O(n)
 * - 使用布尔状态机，逻辑清晰
 * \n * 时间复杂度：O(n) - n为字符串长度
 * 空间复杂度：O(1)
 */

#include <stdio.h>
#include <stdbool.h>

int main() {
    char s[1001];
    scanf("%s", s);
    
    int count = 0;
    bool in_pair = false;
    
    // 单遍扫描字符串
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '|') {
            // 切换配对状态
            in_pair = !in_pair;
        } else if (s[i] == '*' && !in_pair) {
            // 在对外的星号
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}
