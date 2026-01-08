/*对输入的整数序列，按照奇数在前，偶数在后，每类又按照从小到大的顺序排序。
输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，中间用空格隔开，每组数据的第一个整数表述该组数据的个数（不用做排序输出）。

输出
对每组数据，按照奇数在前，偶数在后，每类又按照从小到大的顺序排序输出，中间用空格隔开。

样例
输入
3
7 1 2 3 4 5 6 7
3 8 5 2
4 2 4 4 8

输出
1 3 5 7 2 4 6
5 2 8
2 4 4 8*/
#include <stdio.h>
int main() {
    int n, a[1000], i, j, m;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &m);
        for (j = 0; j < m; j++) {
            scanf("%d", &a[j]);
        }
        
        for (int k = 0; k < m - 1; k++) {
            for (int l = 0; l < m - 1 - k; l++) {
                if (a[l] > a[l + 1]) {
                    int temp = a[l];
                    a[l] = a[l + 1];
                    a[l + 1] = temp;
                }
            }
        }
        
        int first = 1;
        for (int k = 0; k < m; k++) {
            if (a[k] % 2 == 1) {
                if (!first) printf(" ");
                printf("%d", a[k]);
                first = 0;
            }
        }
        
        for (int k = 0; k < m; k++) {
            if (a[k] % 2 == 0) {
                if (!first) printf(" ");
                printf("%d", a[k]);
                first = 0;
            }
        }
        printf("\n");
    }
    return 0;
}