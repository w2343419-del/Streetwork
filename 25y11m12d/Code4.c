/*输入n（1-9），输出n*n乘法表。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行。

输出
对每组数据，输出n*n乘法表，行内两个等式之间用空格隔开，每行输出完毕换行。

样例

输入
2
1
2

输出
1*1=1
1*1=1
2*1=2 2*2=4*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        for (int j = 1; j <= num; j++) {
            for (int k = 1; k <= j; k++) {
                printf("%d*%d=%d", j, k, j * k);
                if (k != j) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}