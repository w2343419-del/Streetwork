/*描述
输入一个长度不超过 1000 的字符串（仅由可见 ASCII 字符组成，可含空格）。
将该字符串中所有连续的空白字符（空格、制表符、换行、回车） 压缩为单个空格，并删除字符串开始的所有空白。
最后输出处理后的字符串。

输入
一行或多行文本，总长度 ≤ 1000，以 EOF 结束。

输出
一行，处理后的字符串。

样例
输入

Hello    world!
   This   is   a   test.
输出

Hello world! This is a test.
输入

   Leading and trailing spaces 
输出

Leading and trailing spaces*/
#include <stdio.h>

int main(){
    char str[1001];
    int len = 0;
    char c;
    
    while((c = getchar()) != EOF && len < 1000){
        str[len++] = c;
    }
    str[len] = '\0';
    int i = 0, j = 0;
    while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'){
        i++;
    }
    while(str[i] != '\0'){
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'){
            while(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'){
                i++;
            }
            if(str[i] != '\0'){
                str[j++] = ' ';
            }
        }
        else{
            str[j++] = str[i++];
        }
    }
    str[j] = '\0';
    int k = 0;
    while(str[k] != '\0'){
        putchar(str[k]);
        k++;
    }
    putchar('\n');
    
    return 0;
}