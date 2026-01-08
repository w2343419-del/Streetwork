/*请用递归函数的形式计算阶乘n!的值(程序中不能出现循环)
输入格式：
多组数据
每组数据输入一个整数n(n <= 20)

输出格式：
输出n!的值

输入
4
5

输出
24
120

提示：在没有给出几组数据时，默认以EOF结尾，即读入函数的返回值==EOF时停止输入*/
#include <stdio.h>

long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

void processInput() {
    int n;
    if (scanf("%d", &n) != EOF) {
        if (n > 20 || n < 0) {
            printf("Input out of range\n");
        } else {
            printf("%lld\n", factorial(n));
        }
        processInput();
    }
}

int main() {
    processInput();
    return 0;
}