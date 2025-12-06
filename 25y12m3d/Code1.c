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

#include <stdio.h>
#include <string.h>

int main() {
    char str1[99999], str2[99999];
    
    scanf("%s", str1);
    scanf("%s", str2);
    
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int count = 0;
    int res = 0;
    int i = 0;
    int k = 0;
    
    for (int j = 0; j < len2; j++) {
        for (k = 0; k < len1; k++) {
            if (str1[k] == str2[j]) {
                count++;
            }
        }
        if (str1[k + count] == str2[j + count]) {
            res++;
        }

    }
    printf("%d", res - 1);
}
