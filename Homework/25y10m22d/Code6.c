/**
 * @brief 判断字符的类型（数字/字母/其他）
 * 
 * 算法思路：
 * 1. 使用isdigit判断数字 ('0'-'9')
 * 2. 使用isalpha判断字母 ('a'-'z' 或 'A'-'Z')
 * 3. 其他字符输出"else"
 * 
 * 时间复杂度：O(n) - n为输入的字符个数
 * 空间复杂度：O(1)
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char ch;
        scanf(" %c", &ch);  // 注意：%c前加空格，避免读取换行符
        
        if (isdigit(ch)) {
            printf("number\n");
        } else if (isalpha(ch)) {
            printf("letter\n");
        } else {
            printf("else\n");
        }
    }
    
    return 0;
}
