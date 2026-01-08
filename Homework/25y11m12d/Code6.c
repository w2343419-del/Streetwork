/**
 * @brief 递归计算阶乘
 * 
 * 算法思路：
 * 使用递归公式：
 * - factorial(0) = 1
 * - factorial(1) = 1
 * - factorial(n) = n * factorial(n-1)
 * 
 * 优化点：
 * - 使用尾递归可被编译器优化
 * - processInput函数实现多组输入处理
 * - 验证输入范围（n <= 20）避免溢出
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(n) - 递归栈深度
 */

#include <stdio.h>

// 递归计算阶乘
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// 处理多组输入的递归函数
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
