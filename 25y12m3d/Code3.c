/*输入一个7进制数m(m可以用32位整型保存)，如果是合法的7进制数那么将之转为2进制数输出。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含1个7进制数。

输出
对符合要求的输入数据，输出一组数据占一行。如果输入不符合要求，则输出ERROR。

样例
输入
2
3
128

输出
11
ERROR*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char m[99999];
        scanf("%s", m);

        int len = strlen(m);
        int count = 0;
        
        for (int j = 0; j < len; j++) {
            if (m[j] < '0' || m[j] > '6') {
                printf("ERROR\n");
                count = 1;
                break;
            }
        }

        if (count == 0) {
            long long p = 0;
            for (int j = 0; j < len; j++) {
                p = p * 7 + (m[j] - '0');
            }
            
            if (p == 0) {
                printf("0\n");
            } else {
                char q[100];
                int l = 0;
                while (p > 0) {
                    q[l++] = (p % 2) + '0';
                    p /= 2;
                }
                for (int k = l - 1; k >= 0; k--) {
                    printf("%c", q[k]);
                }
                printf("\n");
            }
        }
    }
    
    return 0;
}