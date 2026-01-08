/**
 * @brief 回文数判断
 * 
 * 回文数：正序和逆序相同的数字
 * 例：12321是回文数，1234321是回文数
 * 
 * 算法思路：
 * 1. 将数字转换为字符串
 * 2. 比较对称位置的字符
 * 3. 若所有对称位置都相等，则是回文数
 * 
 * 时间复杂度：O(log n) - n的位数
 * 空间复杂度：O(log n)
 */

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int num;
        char str[40];
        scanf("%d", &num);
        
        sprintf(str, "%d", num);
        int len = strlen(str);
        
        int is_palindrome = 1;
        for (int j = 0; j < len / 2; j++) {
            if (str[j] != str[len - 1 - j]) {
                is_palindrome = 0;
                break;
            }
        }
        
        if (is_palindrome) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    
    return 0;
}
