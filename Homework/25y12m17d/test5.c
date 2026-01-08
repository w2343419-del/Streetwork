/*输入一段文本，统计中间出现次数最多的回文数。回文数是类似12321，1221这样，顺序和逆序相同的十进制无符号整数，不考虑符号，长度至少为2，不能以0开始。另外，不考虑数的一部分，即abc1232abc中的232不是一个单独的数。(数据可能超过32位)

输入
输入数据为一段文本，可能包含若干行，直到文件末尾为止。即只有一组测试用例。

输出
对于每一组输入数据，输出出现次数最多的回文数和它出现的次数。如果有多个，按数字从小到大输出，每个数占一行。如果没有， 输出None。

样例
输入

Thin34543king 121 is8 interesting121.
I like121 thinking23.
输出

121 3
提示
本题虽然是找整数，但最好的方法是全部按字符串来处理。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char s[99999];
    
    while (scanf("%s\n", s) != EOF) {
        scanf("%s\n", s);
    }

    int max = 0;
    int count = 0;
    int len = strlen(s);
    int count_max = 0;

    char s1[99999];
    char s2[99999];

    for (int i = 0; s[i] != EOF; i++) {
        if (isdigit(s[i]) && isdigit(s[i + 1])) {
            s1[i] = s[i];
            s1[i + 1] = s[i + 1];
        } else {
            s1[i] = ' ';
        }
    }

    for (int i = 0; i < len; i++) {
        if (isdigit(s1[i])) {
            count++;
        }

    }
    
    return 0;
}