/*描述
给你一个字符串 s。每两个连续竖线 '|' 为一对（第一个和第二个为一对，第三个和第四个为一对，以此类推）。
请你返回不在竖线对之间， s 中星号 '*' 的数目。

注意：
每个竖线 '|' 恰好属于一个对。
字符串保证包含偶数个竖线。
核心思想： 使用一个布尔状态（例如 in_pair）来追踪当前字符是否位于一对竖线内部。每遇到一个竖线 '|'，就切换一次状态。

输入
一行，一个字符串 s（1≤∣s∣≤1000），包含小写英文字母、竖线 '|' 和星号 '*'。

输出
一个整数，表示不在竖线对之间，字符串 s 中星号 '*' 的数目。

样例

输入
l|eet|c**o|*de|

输出
2

输入
yo|uar|e**|b|e***au|tifu|l

输出
5*/
#include <stdio.h>
#include <stdbool.h> 
int main() {
    char s[1001];
    scanf("%s", s);
    int count = 0;
    bool in_pair = false;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '|') {
            in_pair = !in_pair;
        } else if (s[i] == '*' && !in_pair) {
            count++;
        }
    }
    printf("%d\n", count);
}