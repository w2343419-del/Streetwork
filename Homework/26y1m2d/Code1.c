/*输入 4 个十进制整数，计算它们的平方和并输出。

输入 4 个十进制整数，范围是−10000~10000。

输出
输出它们的平方和。

样例
输入
1 2 3 4

输出
30*/

#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    int sum = 0;
    sum = a * a + b * b + c * c + d * d;
    
    printf("%d\n", sum);
    return 0;
}