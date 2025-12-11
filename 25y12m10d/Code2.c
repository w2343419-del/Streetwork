/*给定一个字符串 s，表示学生的出勤记录，其中每个字符表示当天的出勤情况：
A：Absent（缺勤）
L：Late（迟到）
P：Present（到场）

如果同时满足以下两个条件学生可以获得出勤奖励：
缺勤严格少于 2 次 A
不存在连续 3 天或以上迟到 L
请判断学生是否可以获得出勤奖励。如果可以，则输出 1 , 否则输出 0 。

输入
一行字符串 s ，长度 <=100 , 字符串只包含 A 、L 、P 。

输出
可以获得出勤奖励输出 1，否则输出 0 。

样例

输入1
PPALLP

输出1
1

输入2
PPALLLLLPPPP

输出2
0*/
#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    scanf("%s", s);

    int q = 0;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            q++;
        } else if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') {
            q = q + 2;
            break;
        } else if (q >= 2) {
            break;
        }
    }

    if (q == 0 || q == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
