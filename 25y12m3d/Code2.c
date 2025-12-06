/*合并两个有序数组a,b。

输入
第一行输入两个数据m,n，分别代表数组a,b的长度，第二行第三行分别输入两个数组a,b,保证数组有序。

输出
将两个数组合并后输出，保证数组仍然有序。输出数据之间用空格隔开。

样例
输入
3 3
1 3 5
2 4 6

输出
1 2 3 4 5 6*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int a[m + n], b[n];
    

    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for (int i = 0; i < n; i++) {
        a[m + i] = b[i];
    }
    
    qsort(a, m+n, sizeof(int), compare);
    
    for (int i = 0; i < m+n; i++) {
        printf("%d ", a[i]);
    }
    
    return 0;
}
