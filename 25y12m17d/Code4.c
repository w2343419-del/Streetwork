/*波浪数是在一对不同数字之间交替转换的数，如 1212121。
特别地，只有一位的数也算作波浪数，例如 1。

双重波浪数则是指在至少两种进制下都是波浪数的数。
如十进制数 191919 是一个十进制下的波浪数。
它对应的十一进制数 121212 也是一个波浪数。
所以十进制数 191919 是一个双重波浪数。

你的任务就是在指定范围内找出所有双重波浪数。

输入
单独一行包含四个用空格隔开的十进制整数 m,n,L,R。
[m,n] 表示应当考虑的进制的范围，
[L,R] 表示应当考虑的数字的范围。

其中，
2≤m≤n≤32，
1≤L≤R≤10^7
 

输出
从小到大以十进制形式输出指定范围内的指定重数的波浪数。一行输出一个数。
如果没有，那么输出NULL。

样例

输入
10 11 190000 960000

输出
191919
383838
575757
767676
959595

输入
10 11 7 9 

输出
7
8
9*/

#include <stdio.h>
#include <string.h>

int check(char s[], int len) {
    if (len == 1) return 1;
    if (s[0] == s[1]) return 0;

    for (int i = 2; i < len; i++) {
        if (s[i] != s[i - 2]) {
            return 0;
        }
    }
    return 1;
} //判断波浪数

int main() {
    int m, n, L, R;
    if (scanf("%d %d %d %d", &m, &n, &L, &R) != 4) return 0;
    
    int any_found = 0;

    for (int j = L; j <= R; j++) {
        int valid_count = 0;

        for (int i = m; i <= n; i++) {
            char s[40];
            int temp = j;
            int pos = 0;

            while (temp > 0) {
                int rem = temp % i;
                s[pos++] = rem + '0'; 
                temp /= i;
            }
            s[pos] = '\0';

            if (check(s, pos)) {
                valid_count++;
            }
            
            if (valid_count >= 2) break;
        }

        if (valid_count >= 2) {
            printf("%d\n", j);
            any_found = 1;
        }
    }

    if (any_found == 0) {
        printf("NULL\n");
    }

    return 0;
} //主函数