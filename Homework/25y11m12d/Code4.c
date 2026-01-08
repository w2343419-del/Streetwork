/**
 * @brief 输出乘法表
 * 
 * 算法思路：
 * 1. 对于每个n，输出n×n的乘法表
 * 2. 第j行包含1*j=j到j*j=j²共j个等式
 * 3. 等式间用空格分隔，行末换行
 * 
 * 时间复杂度：O(n³) - 对于n组数据，每组n个行，每行n个乘法
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // 输出num×num乘法表
        for (int j = 1; j <= num; j++) {
            for (int k = 1; k <= j; k++) {
                printf("%d*%d=%d", j, k, j * k);
                
                // 不是该行最后一个则输出空格
                if (k != j) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}
