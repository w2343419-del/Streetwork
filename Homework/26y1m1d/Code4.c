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
第一行输入字符串S，长度不超过32。其中可能包含空格。
随后若干行，每行为一组指令。
前半部分为指令串，长度不超过16。随后为整数k，中间以空格分隔。
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

int main() {
    char original[1001];
    fgets(original, sizeof(original), stdin);
    
    int original_len = strlen(original);
    if (original[original_len - 1] == '\n') {
        original[original_len - 1] = '\0';
        original_len--;
    }
    
    char command[33];
    
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "End") == 0) {
            break;
        }

        int k;
        scanf("%d", &k);

        char s[1001];
        strcpy(s, original);
        int len_s = original_len;

        int len_cmd = strlen(command);

        for (int i = 0; i < len_cmd; i++) {
            if (command[i] == 'L') {
                char temp[2002];
                
                for (int j = 0; j < len_s; j++) {
                    temp[2 * j] = s[j];
                    temp[2 * j + 1] = s[j];
                }
                
                int new_len = 2 * len_s;
                
                for (int j = 0; j < new_len; j++) {
                    s[j] = temp[j];
                }
                
                len_s = new_len;
            } else if (command[i] == 'R') {
                char temp[2002];
                
                for (int j = 0; j < len_s; j++) {
                    temp[len_s - 1 - j] = s[j];
                }
                
                for (int j = 0; j < len_s; j++) {
                    s[j] = temp[j];
                }
            } else if (command[i] == 'D') {
                i++;
                int n = 0;
                while (i < len_cmd && command[i] >= '0' && command[i] <= '9') {
                    n = n * 10 + (command[i] - '0');
                    i++;
                }
                i--;
                
                int center = len_s / 2;
                
                int del_start = center - n;
                if (del_start < 0) del_start = 0;
                int del_count = center - del_start;
                
                int new_len = len_s - del_count;
                for (int j = del_start; j < new_len; j++) {
                    s[j] = s[j + del_count];
                }
                
                len_s = new_len;
            }
        }

        if (k > len_s || k <= 0) {
            printf("NULL\n");
        } else {
            printf("%c\n", s[k - 1]);
        }
    }

    return 0;
}
