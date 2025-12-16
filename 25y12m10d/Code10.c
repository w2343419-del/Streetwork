/*在某种语言中，用##来作为注释的开头和结尾。
但是在(...)内的##不是注释的开头和结尾。
只有##也不是完整的注释。
在##...##内不会有##。
请编写程序去掉语句中的所有完整的注释。
例如，对下面的串：
hi, how are you?##no## I am fine...(##hahaha##)...##...
##no##是注释内容，##hahaha##不是，##...也不是。
去掉完整注释的字符串应该是hi, how are you? I am fine...(##hahaha##)...##...

输入
输入一个字符串S，以回车结束，长度不超过100个字符。

输出
输出去掉注释的字符串。

如果去掉注释后的字符串是空串则输出NULL。

样例
输入
hi, how are you?##no## I am fine...(##hahaha##)...##*^*...

输出
hi, how are you? I am fine...(##hahaha##)...##*^*...*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    fgets(s, 101, stdin);

    int len1 = strlen(s);
    int flag = 0;
    int skip = 0;
    int len2 = 0;

    for (int i = 0; i < len1; i++) {
        if (skip == 1) {
            if (s[i] == '#' && i + 1 < len1 && s[i + 1] == '#') {
                skip = 0;
                i++;
            }
        } else {
            if (s[i] == '(') {
                flag = 1;
                putchar(s[i]);
                len2++;
            } else if (s[i] == ')') {
                flag = 0;
                putchar(s[i]);
                len2++;
            } else if (!flag && s[i] == '#' && i + 1 < len1 && s[i + 1] == '#') {
                skip = 1;
                i++;
            } else {
                putchar(s[i]);
                len2++;
            }
        }
    }

    if (len2 == 0) {
        printf("NULL");
    }

    return 0;
}
