/*分解质因数，将一个数表示为质因数相乘的形式，如，30=2*3*5。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含1个整数num。

输出
对每组数据，输出num表示为质因数相乘的形式，因子按照从小到大的顺序排序，并换行。

样例

输入
3
1
11
12

输出
1
11
2*2*3*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        if (num == 1) {
            printf("1\n");
            continue;
        }
        
        int first = 1;
        int factor = 2;
        int temp = num;
        
        while (temp > 1) {
            while (temp % factor == 0) {
                if (!first) {
                    printf("*");
                }
                printf("%d", factor);
                first = 0;
                temp /= factor;
            }
            factor++;
        }
        printf("\n");
    }
    
    return 0;
}