/*给定一个正整数 n，判断它是不是完全数（除自身外所有正因子之和等于 n）
例：6 = 1 + 2 + 3，所以6是完全数

输入
一个正整数 n(1 ≤ n ≤ 10⁸)。

输出
一个整数：1 表示 n 是完全数，0 表示不是。

样例
输入

28
输出

1
输入

12
输出

0*/
#include <stdio.h>
int main() {
    int a;
    int i;
    int sum = 1; 
    scanf("%d", &a);
    
    if (a == 1) {
        printf("0\n");
        return 0;
    }
    
    for (i = 2; i * i < a; i++) {
        if (a % i == 0) {
            sum += i + a/i; 
        }
    }
    
    if (i * i == a) {
        sum += i;
    }
    
    if (sum == a) {
        printf("1\n");
    } else {
        printf("0\n");
    }
    
    return 0;
}

