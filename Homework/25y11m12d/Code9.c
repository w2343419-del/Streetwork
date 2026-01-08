/*描述
斐波那契数列指
Fn=Fn−1+Fn−2
F1=F2=1
我们定义新斐波那契数列为
Fn=2∗Fn−1+3Fn−2+5∗Fn−3
F1=F2=F3=1

输入
第1行是一个整数 n，表示随后有 n 组数据。每组数据占一行，为所求新斐波那契数列的下标 n (n≤30)

输出
每组数据输出一行，为所求新斐波那契数列的值(提示：long long型数据的输出格式为%lld)

样例
输入
3
9
16
28

输出
3493
16357465
32002027134220*/
#include <stdio.h>

int main() {
    int n, index;
    long long fib[31];
    
    fib[1] = 1;
    fib[2] = 1;
    fib[3] = 1;
    
    for (int i = 4; i <= 30; i++) {
        fib[i] = 2 * fib[i - 1] + 3 * fib[i - 2] + 5 * fib[i - 3];
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &index);
        printf("%lld\n", fib[index]);
    }
    
    return 0;
}