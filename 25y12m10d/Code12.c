/*假设一元一次方程中只包含整数、小写字母及+、-、=这三个数学符号(当然，符号“-”既可作减号，也可作负号)。
方程中并没有括号，没有除号，也没有空白字符。方程中的字母表示未知数。
请编写程序求解一元一次方程。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，是一个一元一次方程，中间没有空白字符。

输出
对每组数据输出方程的解，精确到小数点后6位。

样例
输入
3
2x=4
4+x=8
-3=y

输出
x=2.000000
x=4.000000
y=-3.000000*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char s[99999];
        fgets(s, 99999, stdin);

        int len = strlen(s);
        
        if (len > 0 && s[len-1] == '\n') {
            s[len-1] = '\0';
        }

        int a = 0, b = 0;
        int sign = 1;
        int num = 0;
        int has_num = 0;
        int after_equal = 0;
        char unknown = 'x';

        for (int j = 0; s[j] != '\0'; j++) {
            if (s[j] == '=') {
                if (has_num) {
                    b += sign * num;
                } else if (j > 0 && isalpha(s[j-1])) {
                    a += sign;
                }
                after_equal = 1;
                sign = 1;
                num = 0;
                has_num = 0;
            } 
            else if (s[j] == '+' || s[j] == '-') {
                if (has_num) {
                    if (!after_equal) {
                        b += sign * num;
                    } else {
                        b -= sign * num;
                    }
                } else if (j > 0 && isalpha(s[j-1])) {
                    if (!after_equal) {
                        a += sign;
                    } else {
                        a -= sign;
                    }
                }
                
                sign = (s[j] == '+') ? 1 : -1;
                num = 0;
                has_num = 0;
            } 
            else if (isdigit(s[j])) {
                num = num * 10 + (s[j] - '0');
                has_num = 1;
            } 
            else if (isalpha(s[j])) {
                unknown = s[j];
                if (has_num) {
                    if (!after_equal) {
                        a += sign * num;
                    } else {
                        a -= sign * num;
                    }
                } else {
                    if (!after_equal) {
                        a += sign;
                    } else {
                        a -= sign;
                    }
                }
                num = 0;
                has_num = 0;
            }
        }
        
        if (has_num) {
            if (after_equal) {
                b += sign * num;
            } else {
                b -= sign * num;
            }
        }

        double res = -(double)b / a;
        printf("%c=%.6f\n", unknown, res);
    }
    return 0;
}
    