/*输入一串字符串，统计里面有几个数字(连续的数字算一个数字）。
例如输入asdad12asda43eftr45-23-3--22-，输出6。
12，43，45，23，3，22为该字符串的6个数字。

输入
第1行是一个整数n，表示随后有n组数据。每组数据输入一串字符串。

输出
输出字符串中数字个数。

样例

输入
2
23frw90ewe3**325%
45dsfafag2

输出
4
2*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char s[1000];
        scanf("%s", s);

        int count = 0;
        int j = 0;
        while (s[j] != '\0') {
            if (s[j] >= '0' && s[j] <= '9') {
                count++;
                while (s[j] >= '0' && s[j] <= '9') {
                    j++;
                }
            } else {
                j++;
            }
        }
        printf("%d\n", count);
    }
    
    return 0;
}