/*给你一个n∗n的矩阵A，计算矩阵A的k次方
矩阵乘法的定义为：若A,B,C都是矩阵，A∗B=C，那么有Ci,j = k=0 ∑ n−1 ​(Ai,k ∗ Bk,j)

输入
第一行为矩阵的阶数n，以及k次方。
接下来n行，每行有n个数，分别用空格分开。代表矩阵A。
其中1≤n,k≤7，且矩阵A中每个元素满足 1≤Ai,j≤7。

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

int power(int k) {
	int i;
	if (i = k) {
		return 1;
	}
	
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    int A[7][7];
    int temp[7][7];
    int rst[7][7];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &A[i][j]);
        }
    }
	
	
	

}
