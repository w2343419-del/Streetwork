/*输入两个字符串str1和str2，判断字符串str1包含字符串str2的个数，允许重叠。
例如：
01101010101
1010
输出3。

输入
分别输入两个字符串str1和str2，分别占一行。

输出
输出str1包含str2的个数。

样例

输入
ababababac
abab

输出
3*/

/**
 * @brief 统计字符串重叠出现次数
 * 
 * 算法思路：
 * 1. 从头开始遍历str1
 * 2. 每次找到str2，计数+1
 * 3. 然后从当前位置+1继续查找（允许重叠）
 * 
 * 例如：ababababac 中查找 abab
 * - 位置0: abab ✓
 * - 位置2: abab ✓
 * - 位置4: abab ✓
 * 总计: 3次
 * 
 * 时间复杂度：O(len1 * len2)
 * 空间复杂度：O(1)
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str1[100000], str2[100000];
    
    scanf("%s", str1);
    scanf("%s", str2);
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int count = 0;
    
    // 遍历str1，查找所有出现位置
    for (int i = 0; i <= len1 - len2; i++) {
        // 使用strncmp比较子串
        if (strncmp(&str1[i], str2, len2) == 0) {
            count++;
        }
    }
    
    printf("%d\n", count);
    return 0;
}
