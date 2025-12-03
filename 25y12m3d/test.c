/*输入一个正整数， 判断它是不是一个伪回文数。（回文数是顺着看和倒着看都一样的数，例如1221，12321都是回文数，伪回文数是改动一个数字就能变成回文数的数，1位数不是伪回文数）。

输入
第一行输入一个正整数n，表示下面有n组数据。
每组数据为一个正整数，能够用int保存，占用一行。

输出
对于每组数据，若是伪回文数，输出yes，否则输出no

样例
输入

2
122
12321
输出

yes
no*/
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int count = 0; count < n; count++) {
        char str[40];
        if (scanf("%s", str) != 1) continue;
        
        int len = strlen(str);
        
        if (len <= 1) {
            printf("no\n");
            continue;
        }
        
        int is_pseudo = 0;
        int i = 0; 
        int j = len - 1;

        while (i < j) {
            if (str[i] != str[j]) {
                
                int l1 = i + 1;
                int r1 = j;
                int sub1_ok = 1;
                
                while (l1 < r1) {
                    if (str[l1] != str[r1]) {
                        sub1_ok = 0;
                        break;
                    }
                    l1++;
                    r1--;
                }
                
                int l2 = i;
                int r2 = j - 1;
                int sub2_ok = 1;
                
                while (l2 < r2) {
                    if (str[l2] != str[r2]) {
                        sub2_ok = 0;
                        break;
                    }
                    l2++;
                    r2--;
                }
                
                if (sub1_ok || sub2_ok) {
                    is_pseudo = 1;
                }
                
                break;
            }
            i++;
            j--;
        }
        
        if (is_pseudo) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    
    return 0;
}