/*将数组中的0移到末尾。
输入
第1行是一个整数n，表示随后有n组数据。
每组数据包含2行，第1行是表示元素个数的整数m，第2行是数组元素。

输出
对每组数据，将数组中的0移到数组末尾，其他元素保持原来的顺序往前移，输出数组元素，以空格隔开，并换行。

样例
输入
1
10
1 2 0 6 4 0 8 0 9 18

输出
1 2 6 4 8 9 18 0 0 0*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        int a[m];
        int count = 0;
        
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[j]);
            if (a[j] != 0) {
                printf("%d ", a[j]);
            } else {
                count++;
            }
        }
        for (int j = 0; j < count; j++) {
            printf ("0 ");
        }
        printf("\n");
    }
    
    return 0;

}