/*描述
有两个数组a和b，从a中取一个数，从b中取一个数，计算差的绝对值。
把所有绝对值中最大的值作为两个数组的距离。

输入
每个数组占1行，第1个数是数组元素的个数n(n不超过10)，后面是n个整数。

输出
输出两个数组的距离。

样例

输入
3 1 2 3
4 1 2 3 4

输出
3*/
#include <stdio.h>

void compare1(int a[], int m, int *max1, int *min1) {
    *max1 = a[0];
    *min1 = a[0];
    for (int j = 1; j < m; j++) {
        if (a[j] > *max1) {
            *max1 = a[j];
        }
        if (a[j] < *min1) {
            *min1 = a[j];
        }
    }
}

void compare2(int b[], int n, int *max2, int *min2) {
    *max2 = b[0];
    *min2 = b[0];
    for (int k = 1; k < n; k++) {
        if (b[k] > *max2) {
            *max2 = b[k];
        }
        if (b[k] < *min2) {
            *min2 = b[k];
        }
    }
}

void compare3(int max1, int min1, int max2, int min2) {
    int dist1 = max1 - min2;
    int dist2 = max2 - min1;
    if (dist1 > dist2) {
        printf("%d\n", dist1);
    } else {
        printf("%d\n", dist2);
    }
}

int main() {
    int m, n;
    int a[10], b[10];

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int max1, min1, max2, min2;

    compare1(a, m, &max1, &min1);
    compare2(b, n, &max2, &min2);
    compare3(max1, min1, max2, min2);

    return 0;
}