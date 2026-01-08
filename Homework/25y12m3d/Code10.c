/*计算两个大整数的和。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含两个整数a,b，0≤a,b≤10^500。

输出
对每组数据输出两个整数的和，并换行。

样例
输入
3
1 2
5 8
1 999

输出
3
13
1000*/

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char a[501], b[501];
        scanf("%s %s", a, b);

        int len_a = strlen(a);
        int len_b = strlen(b);

        int j = len_a - 1;
        int k = len_b - 1;
        
        char result[502];
        int res = 0;
        int pos = 0;

        while (j >= 0 || k >= 0 || res) {
            int digit_a = 0;
            int digit_b = 0;
            
            if (j >= 0) {
                digit_a = a[j] - '0';
            }
            
            if (k >= 0) {
                digit_b = b[k] - '0';
            }
            
            int temp = digit_a + digit_b + res;
            result[pos++] = temp % 10 + '0';
            res = temp / 10;
            
            j--;
            k--;
        }

        for (int m = pos - 1; m >= 0; m--) {
            printf("%c", result[m]);
        }
        printf("\n");
    }

    return 0;
}