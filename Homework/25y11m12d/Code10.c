/*描述
有如下定义：f(n)=(∑i=1n(i!)) % 1000000
其中 i! 是阶乘运算，% 是取模运算。

输入
第一行为正整数 k,(1≤k≤100)，表示随后有 k 组数据。每组数据占一行，为一个正整数 n,(1≤n≤1000000)。

输出

对每组数据 n，输出 f(n)，并换行。

样例

输入
3
1
5
10

输出
1
153
37913*/
#include <stdio.h>
#define MOD 1000000

int main() {
    int k, n;
    static long long fact[1000001];
    static long long sum[1000001];
    
    fact[0] = 1;
    fact[1] = 1;
    sum[1] = 1;
    
    for (int i = 2; i <= 1000000; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        sum[i] = (sum[i-1] + fact[i]) % MOD;
    }
    
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d", &n);
        printf("%lld\n", sum[n]);
    }
    
    return 0;
}