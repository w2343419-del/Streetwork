/*给定一个正整数 n。n 中的每一位数字会按照下述规则分配一个符号：

最高有效位（最左边）上的数字分配到正号 (+)。
剩余每位上的数字的符号都与其相邻数字相反。
返回所有数字及其对应符号的和。

例如：n=12345， 那么和s=1−2+3−4+5=3

输入
一行，一个正整数 n(1≤n≤10 ^9)。

输出
一个整数，表示所有数字及其对应符号的和。

样例
输入

521
输出

4
输入

886996
输出

0*/
#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    scanf("%s", s);
    
    int sum = 0;
    int len = strlen(s);
    for (int i = 0; i < strlen(s); i++) {
        int digit = s[i] - '0';
        
        if (i % 2 == 0) {
            sum += digit;
        } else {
            sum -= digit;
        }
    }
    
    printf("%d", sum);

    return 0;
}
