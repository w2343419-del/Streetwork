/**
 * @brief 递归逆序输出字符串
 * 
 * 算法思路：
 * 使用递归实现字符串逆序：
 * 1. 递归遍历到字符串末尾
 * 2. 从末尾开始回溯时输出字符
 * 
 * 递归过程：
 * put("abcd") → put("bcd") → put("cd") → put("d") → put("") → 返回
 * 返回时依次输出：d, c, b, a
 * \n * 时间复杂度：O(n) - n为字符串长度
 * 空间复杂度：O(n) - 递归栈深度
 */

#include <stdio.h>

// 递归输出字符串（实现逆序）
void put(char *str) {
    if (*str == '\0') {
        return;
    }
    
    // 先递归到末尾
    put(str + 1);
    
    // 回溯时输出
    printf("%c", *str);
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char str[1000];
        scanf("%s", str);
        
        put(str);
        printf("\n");
    }
    
    return 0;
}
