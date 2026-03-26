/*1: A + B
描述
计算两个整数的和。

输入
第 1 行是一个整数 n，表示随后有 n 组数据。每组数据占一行，包含两个整数，用空格隔开。

输出
对每组数据输出两个整数的和，并换行。

样例
输入

3
1 2
5 8
1 999
输出

3
13
1000
提示
请从标准输入读入数据，将结果输出到标准输出。详见示例程序
输入数据包含多组数据，可以读一组，计算一组，输出一组。

示例程序：
C/C++代码

#include <stdio.h>

int main() {
    int n, i, a, b;

    scanf("%d", &n);  // 有n组数据
    for (i = 0; i < n; i++) {
        scanf("%d%d", &a, &b);  // 读入两个整数
        printf("%d\n", a + b);  // 输出两个整数的和
    }

    return 0;
}

Java代码

import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int a = scanner.nextInt();
            int b = scanner.nextInt();
            System.out.println(a + b);
        }
    }
}
Python代码

n = int(input())
for i in range(n):
    s = input().split()
    a = int(s[0])
    b = int(s[1])
    print(a + b)
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", a + b);
    }

    return 0;
}