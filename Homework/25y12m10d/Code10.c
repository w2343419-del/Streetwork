/**
 * @brief 去除字符串中的注释（##...##）
 * 
 * 问题描述：
 * 删除##...##注释，但括号内的##不算注释标记
 * 
 * 算法分析：
 * - 维护括号计数器和注释状态标志
 * - 括号内的##不触发注释状态
 * - 括号外遇到成对##删除其间内容
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */
/*在某种语言中，用##来作为注释的开头和结尾。
但是在(...)内的##不是注释的开头和结尾。
只有##也不是完整的注释。
在##...##内不会有##。
请编写程序去掉语句中的所有完整的注释。
例如，对下面的串：
hi, how are you?##no## I am fine...(##hahaha##)...##...
##no##是注释内容，##hahaha##不是，##...也不是。
去掉完整注释的字符串应该是hi, how are you? I am fine...(##hahaha##)...##...
*/

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
            // 在注释内部，寻找##结束标记
            if (s[i] == '#' && i + 1 < len1 && s[i + 1] == '#') {
                skip = 0;  // 注释结束
                i++;
            }
        } else {
            if (s[i] == '(') {
                // 进入括号，括号内的##不是注释标记
                flag = 1;
                putchar(s[i]);
                len2++;
            } else if (s[i] == ')') {
                // 离开括号
                flag = 0;
                putchar(s[i]);
                len2++;
            } else if (!flag && s[i] == '#' && i + 1 < len1 && s[i + 1] == '#') {
                // 在括号外遇到##，进入注释模式
                skip = 1;
                i++;
            } else {
                // 普通字符，输出
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
