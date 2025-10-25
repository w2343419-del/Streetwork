/*描述
输入一个字符 ch。
若 ch 为小写字母，输出对应大写字母及其 ASCII 码；
若 ch 为大写字母，输出对应小写字母及其 ASCII 码；
对于其它字符，原样输出该字符及其 ASCII 码。

输入
一个字符。

输出
转换后的字符和十进制ASCII码，中间1个空格。

样例
输入

a
输出

A 65
输入

@
输出

@ 64*/
#include <stdio.h>
int main()
{
    char ch, x;
    char res, y;
    scanf("%c", &ch);
    x=ch;
    
    if (ch>='a' && ch<='z')
    {
        res=ch-32;
        y=x-32;   
    }
    
    else if (ch>='A' && ch<='Z')
    {
        res=ch+32;
        y=x+32;
    }
    
    else
    {
        res=ch;
        y=x;
    }

    printf("%c %d", res, y);
    return 0;
}