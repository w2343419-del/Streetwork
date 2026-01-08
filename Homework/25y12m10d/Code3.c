/*给定一个正整数 number 和一个数字 d，
你需要从 number 中移除一个d，构成一个新的数字，
请你找出所有可能的新数字中最大的那一个输出。

如果在 number 中 d 没有出现过，则输出 number。

输入
输入正整数 number 和一个数字 d， 中间用空格间隔。

输出
输出新数字中最大的那一个。

样例

输入1
123 3

输出1
12
说明：“123” 中只有一个 ‘3’ ，在移除 ‘3’ 之后，结果为 “12” 。

输入2
1231 1

输出2
231
说明：可以移除第一个 ‘1’ 得到 “231” 或者移除第二个 ‘1’ 得到 “123” 。
由于 231 > 123 ，返回 “231”。

输入3
123 4

输出3
123*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char number[99999];
    int d;

    scanf("%s %d", number, &d);

    int len = strlen(number);
    int count = 0;

    for (int i = 0; i < len; i++) {
        if (number[i] == d + '0') {
            count++;
        }
    }

    if (count == 0) {
        printf("%s\n", number);
        return 0;
    } 
    
    char a[99999] = "";
    strcpy(a, "0");

    for (int i = 0; i < len; i++) {
        if (number[i] == d + '0') {
            char b[99999];
            int index = 0;

            for (int j = 0; j < len; j++) {
                if (j != i) {
                    b[index++] = number[j];
                }
            }
            b[index] = '\0';

            if (strcmp(b, a) > 0) {
                strcpy(a, b);
            }
        }
    }
        
    printf("%s\n", a);
    return 0;
}
