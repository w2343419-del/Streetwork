/*描述

输入一个整数n（n> 0），计算1/3-2/5+3/8-4/12+5/17。。。前n项的值，结果保留4位小数

输入

第1行是一个整数n，表示随后有n组数据。每组数据占一行。

输出

每组输入的结果保留4位小数，并换行。

样例

输入           输出

2

1                 0.3333

2                -0.0667
*/
#include <stdio.h>
int main() {
    int n;
    scanf ("%d", &n);
    
    for (int i = 0; i < n; i++) {
        double sum = 0.0000;
        int a;
        scanf ("%d", &a);

        for (int j = 1; j <= a; j++) {
            double c = j;
            double d = j * ( j + 1 ) / 2 + 2;
            double e = c / d;
           
            if ( j % 2 == 0 ) {
                sum -= e;
            } else {
                sum += e;
            }
        }
        printf ("%.4lf\n", sum);
    }
    return 0;
}