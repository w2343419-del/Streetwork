/* 题目描述
输入两个整数 |a| , b，输出它们的和（|a|,|b| <= 10 ^ 9）。

注意
1. Pascal 使用 `integer` 会爆掉哦！
2. 有负数哦！
3. C/C++ 的 main 函数必须是 `int` 类型。程序正常结束时的返回值必须是 0。这不仅对洛谷其他题目有效，而且也是 NOIP/CSP/NOI 比赛的要求！

输入格式
两个以空格分开的整数。

输出格式
一个整数。

输入输出样例

输入
20 30

输出
50*/

#include <stdio.h>
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", a+ b);
    return 0;
}