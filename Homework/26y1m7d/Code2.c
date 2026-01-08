/**
 * @brief 矩阵快速幂
 * 
 * 问题描述：
 * 计算n×n矩阵A的k次方
 * 
 * 算法分析：
 * - 矩阵乘法：C[i][j] = Σ(A[i][k] × B[k][j])
 * - 矩阵快速幂：利用二分思想，A^k = (A^(k/2))²
 * - 时间复杂度：O(n³ × log k) 使用快速幂
 * - 时间复杂度：O(n³ × k) 暴力连乘
 * - 空间复杂度：O(n²)
 * 
 * 实现方式：
 * k次连续的矩阵乘法
 */

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
