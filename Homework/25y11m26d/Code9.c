/*输入两个整数（大于等于0，小于等于10的30次方），输出较小的那个数，如果输入的值不满足前面的条件，则输出Input Error。

输入
第一行是一个整数n，表示一共有n组测试用例；
下面一共有n组输入，每组输入两个正整数，用空格隔开

输出
对于每一组输入数据，输出较小的那个数，每组输出单独占一行

样例

输入
4
1234567 12345678474537585686857572
a 2
-1 12
12324 ab

输出
1234567
Input Error
Input Error
Input Error
*/

#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char a[200], b[200];

    for (int i = 0; i < n; i++) {
        scanf("%s %s", a, b);

        int len1 = strlen(a);
        int len2 = strlen(b);
        int valid = 1;

        for (int j = 0; j < len1; j++) {
            if (a[j] < '0' || a[j] > '9') {
                valid = 0;
                break;
            }
        }
        
        for (int j = 0; j < len2; j++) {
            if (b[j] < '0' || b[j] > '9') {
                valid = 0;
                break;
            }
        }
        
        if (len1 > 31 || len2 > 31) {
            valid = 0;
        }

        if (valid == 0) {
            printf("Input Error\n");
        } else {
            if (len1 < len2) {
                printf("%s\n", a);
            } else if (len1 > len2) {
                printf("%s\n", b);
            } else {
                int found = 0;
                
                for (int k = 0; k < len1; k++) {
                    if (a[k] < b[k]) {
                        printf("%s\n", a);
                        found = 1;
                        break;
                    } else if (a[k] > b[k]) {
                        printf("%s\n", b);
                        found = 1;
                        break;
                    }
                }
                
                if (found == 0) {
                    printf("%s\n", a);
                }
            }
        }
    }
    
    return 0;
}