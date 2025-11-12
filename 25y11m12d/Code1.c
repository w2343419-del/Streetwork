/*描述
现有一堆由1,2,3,...,n(n≥1)组成的共 n−1 个数，其中丢失了一个数k，请找出这个数。

输入
第一行m，表示测试数据的组数。

接下来m行，每行即为一组测试样例。每组样例有n(n≤1000)个正整数，其中最后一个整数为0，表示结束，不参与计算。

输出
对每组数据，输出1至n中缺失的那个整数。

样例
输入

2
2 3 1 5 0
1 2 6 4 5 7 0
输出

4
3*/
#include <stdio.h>
#include <string.h>

int main() {
    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int seen[1002] = {0};
        int num, count = 0;

        while (1) {
            scanf("%d", &num);
            if (num == 0) break;
            
            seen[num] = 1;
            count++;
        }

        int n = count + 1;
        for (int j = 1; j <= n; j++) {
            if (!seen[j]) {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}
