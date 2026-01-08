/*给你一个n∗n的矩阵A，计算矩阵A的k次方，即计算k个A∗A∗...∗A
​矩阵乘法的定义为：若A,B,C都是矩阵，A∗B=C，那么有Ci,jk=0∑n−1(Ai,k∗Bk,j)

输入
第一行为矩阵的阶数n，以及k次方。
接下来n行，每行有n个数，分别用空格分开。代表矩阵A。
其中1≤n,k≤7，且矩阵A中每个元素满足 
1≤Ai,j≤7。

输出
输出一个n∗n的矩阵，代表计算结果

样例

输入
3 2
2 1 5
2 5 7
7 3 3

输出
41 22 32
63 48 66
41 31 65*/

#include <stdio.h>
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    long long a[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lld", &a[i][j]);
        }
    }

    long long result[n][n], temp[n][n];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j];
        }
    }
    
    for (int t = 1; t < k; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = 0;
                
                for (int p = 0; p < n; p++) {
                    temp[i][j] += result[i][p] * a[p][j];
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = temp[i][j];
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            printf("%lld", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}