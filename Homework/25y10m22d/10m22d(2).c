/**
 * @brief 字符大小写转换及ASCII码输出
 * 
 * 算法思路：
 * 1. 检查是否为小写字母 (a-z)：转大写，ASCII-32
 * 2. 检查是否为大写字母 (A-Z)：转小写，ASCII+32
 * 3. 其他字符原样输出
 * 
 * 优化点：移除冗余变量，直接使用转换后的字符计算ASCII
 * 
 * 时间复杂度：O(1)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    char ch;
    scanf("%c", &ch);
    
    if (ch >= 'a' && ch <= 'z') {
        // 小写转大写
        char upper = ch - 32;
        printf("%c %d\n", upper, upper);
    } else if (ch >= 'A' && ch <= 'Z') {
        // 大写转小写
        char lower = ch + 32;
        printf("%c %d\n", lower, lower);
    } else {
        // 其他字符
        printf("%c %d\n", ch, ch);
    }
    
    return 0;
}
