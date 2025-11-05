/*描述
输入一个正整数，判断十进制有多少位。

输入
第1行是一个整数n，表示随后有n组数据。
每组数据占一行，包含一个正整数。

输出
对于每一组数据，输出此正整数包含的十进制位数。

样例
输入

3
1
10
100
输出

1
2
3
*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);

        int digits = 0;
        int temp = num;
        while ( temp >0 ) {
            temp /= 10;
            digits++;
        }
        printf("%d\n", digits);
    }
    return 0;
}