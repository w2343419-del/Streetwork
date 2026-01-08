/**
 * @brief 输出直角杨辉三角
 * 
 * 问题描述：
 * 输出n行直角杨辉三角，每个数用逗号分隔
 * 
 * 算法分析：
 * - 杨辉三角规律：
 *   - 第1个和最后1个均为1
 *   - 其余数 = 正上方 + 左上方
 * - 时间复杂度：O(n²)
 * - 空间复杂度：O(n²)
 * 
 * 数学原理：
 * C(n,k) = C(n-1,k-1) + C(n-1,k)
 */

#include <stdio.h>
int main() {
    int n; 
    scanf("%d", &n);
    if (n <= 0 || n > 20) {
        printf("Input Error\n");
        return 0;
    } else {
        int j;
        int a[20][20] = {0};
        for (int i = 0; i < n; i++) {
            for (j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                }
                printf("%d,", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}