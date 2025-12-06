/*输入一行语句，把里面每个单词都逆序输出，其他符号保持不变。

输入
每个输入包含一个测试用例，输入一行语句，长度不超过1000个字符。

输出
每组输出占一行，输出每个单词逆序后的语句。

样例
输入
I like thinking...

输出
I ekil gnikniht...*/
#include <stdio.h>
int main() {
    char s[1000];
    int idx = 0;
    char c;
    while (scanf("%c", &c) == 1 && c != '\n') {
        s[idx++] = c;
    }
    s[idx] = '\0';
    
    int i = 0, j = 0;
    while (s[i] != '\0') {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            j = i;
            while ((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= 'A' && s[j] <= 'Z')) {
                j++;
            }
            for (int k = j - 1; k >= i; k--) {
                printf("%c", s[k]);
            }
            i = j;
        } else {
            printf("%c", s[i]);
            i++;
        }
    }
    printf("\n");
    
    return 0;
}
