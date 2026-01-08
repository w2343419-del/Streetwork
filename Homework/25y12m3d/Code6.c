//请在输入的一段字符串里面查找给定的子串，找到后用/* */注释起来再输出。子串不区分大小写，即one、One和ONE是同一个子串。另外子串不会重叠出现。

//输入
//每个输入包含一个测试数据，第一行输入一行待查找的字符串，以回车结束。

//第二行输入要查找的子串，以回车结束。字符串最长长度不超过 100。

//输出
//如果找到子串，则在子串前面加/*，后面加上*/， 把子串(保持原样)注释起来再输出。没有找到就输出原字符串。

//样例1

//输入
//You are the best!
//are

//输出
//You /*are*/ the best!

//样例2

//输入
//You are the best!
//E

//输出
//You ar/*e*/ th/*e*/ b/*e*/st!

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char a[101];
    char b[101];
    
    fgets(a, 101, stdin);
    fgets(b, 101, stdin);

    int len1 = strlen(a);
    if (a[len1 - 1] == '\n') a[len1 - 1] = '\0', len1--;
    
    int len2 = strlen(b);
    if (b[len2 - 1] == '\n') b[len2 - 1] = '\0', len2--;

    for (int i = 0; i < len2; i++) {
        b[i] = toupper(b[i]);
    }

    for (int i = 0; i < len1; i++) {
        int match = 1;
        for (int j = 0; j < len2; j++) {
            if (i + j >= len1 || toupper(a[i + j]) != b[j]) {
                match = 0;
                break;
            }
        }

        if (match == 1) {
            printf("/*");
            for (int j = 0; j < len2; j++) {
                printf("%c", a[i + j]);
            }
            printf("*/");
            i += len2 - 1;
        } else {
            printf("%c", a[i]);
        }
    }

    return 0;
}