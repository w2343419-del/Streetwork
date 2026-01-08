/*小白是一个字符操作员，对于给定的一行字符串，他根据输入的指令串对字符串进行操作，指令包括：
L：把字符串膨胀2倍，例如 abc -> aabbcc
R：把字符串进行翻转，例如 abc -> cba
Dn，其中n为一个整数：删除中心左侧的n个字母，如果字符数不够，则删除左侧全部字符，例如
D1：abcde -> acde
D2：abcde -> cde
D1：abcd -> acd
D3：abcd -> cd
请编写程序帮助小白完成他的工作，并计算执行完成指令串后字符串第k(从1开始计)个位置上的字母是什么？

输入
第一行输入字符 S，长度不超过32。其中可能包含空格。
随后若干行，每行为一组指令。前半部分为指令串，长度不超过16。随后为整数k，中间以空格分隔。
指令End表示结束输入。
可以保证，执行指令过程中的字符串长度不会超过1000。

输出
对每一组指令，按照要求从字符串S开始，依次执行指令后，得到一个字符串，输出该字符串第k个位置上的字符。

如果没有满足条件的字符则输出NULL。

每组指令都在原始字符串上进行操作，每组指令的输出占一行。

样例

输入
abcd
RD2L 3
D3R 20
End

输出
a
NULL

解释
对于第1条指令，abcd -> dcba -> ba -> bbaa，所以第3个字符是a；
对于第2条指令，abcd -> cd -> dc，没有第20个字符，所以结果是NULL。*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1001];
    char a[1001];
    int len;
    char cmd[25];
    
    fgets(a, sizeof(a), stdin);
    int a_len = strlen(a);
    
    if (a_len > 0 && a[a_len-1] == '\n') {
        a[a_len-1] = '\0';
        a_len--;
    }
    
    while (1) {
        scanf("%s", cmd);
        
        if (cmd[0] == 'E' && cmd[1] == 'n' && cmd[2] == 'd') {
            break;
        }

        int k;
        scanf("%d", &k);
        strcpy(s, a);
        len = a_len;
        
        for (int i = 0; cmd[i] != '\0';) {
            if (cmd[i] == 'L') {
                char temp[1001];
                int temp_len = 0;
                
                for (int j = 0; j < len; j++) {
                    temp[temp_len++] = s[j];
                    temp[temp_len++] = s[j];
                }
                
                temp[temp_len] = '\0';
                strcpy(s, temp);
                len = temp_len;
                i++;
            } else if (cmd[i] == 'R') {
                for (int j = 0; j < len/2; j++) {
                    char temp = s[j];
                    s[j] = s[len-1-j];
                    s[len-1-j] = temp;
                }
                i++;
            } else if (cmd[i] == 'D') {
                int n = 0;
                int j = i + 1;
                
                while (cmd[j] >= '0' && cmd[j] <= '9') {
                    n = n * 10 + (cmd[j] - '0');
                    j++;
                }
                
                int c = len / 2;
                int start = c - n;
                if (start < 0) start = 0;
                
                for (int idx = c; idx < len; idx++) {
                    s[start++] = s[idx];
                }
                
                len = start;
                s[len] = '\0';
                
                i = j;
            } else {
                i++;
            }
        }

        if (k > len || k <= 0) {
            printf("NULL\n");
        } else {
            printf("%c\n", s[k - 1]);
        }
    }

    return 0;
} 