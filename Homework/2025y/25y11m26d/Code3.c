/**
 * @brief 求两个字符串的最长相同后缀
 * 
 * 算法思路：
 * 1. 从两个字符串的末尾开始比较
 * 2. 统计相等的字符个数
 * 3. 输出最后count个字符\n * 优化点：
 * - 倒序比较避免了反转
 * - 只遍历一次，时间复杂度O(min(len1, len2))\n * 时间复杂度：O(min(len1, len2))
 * 空间复杂度：O(1)（不计输入存储）
 */

#include <stdio.h>
#include <string.h>

int main() {
    char a[99999], b[99999];
    scanf("%s %s", a, b);
    
    int len1 = strlen(a);
    int len2 = strlen(b);
    int count = 0;
    
    // 从末尾开始比较
    int i = len1 - 1;
    int j = len2 - 1;
    
    while (i >= 0 && j >= 0 && a[i] == b[j]) {
        count++;
        i--;
        j--;
    }
    
    if (count == 0) {
        printf("null\n");
    } else {
        // 输出最长相同后缀
        for (int k = len1 - count; k < len1; k++) {
            printf("%c", a[k]);
        }
        printf("\n");
    }
    
    return 0;
}
