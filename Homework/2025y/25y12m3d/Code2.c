/*合并两个有序数组a,b。

输入
第一行输入两个数据m,n，分别代表数组a,b的长度，第二行第三行分别输入两个数组a,b,保证数组有序。

输出
将两个数组合并后输出，保证数组仍然有序。输出数据之间用空格隔开。

样例
输入
3 3
1 3 5
2 4 6

输出
1 2 3 4 5 6*/

/**
 * @brief 合并两个有序数组
 * 
 * 算法思路：
 * 方法1：直接合并+qsort（原代码）- O((m+n)log(m+n))
 * 方法2：归并算法（优化）- O(m+n)
 * 
 * 这里使用归并算法：
 * 1. 使用两个指针分别指向a和b
 * 2. 比较当前元素，取较小者放入结果数组
 * 3. 移动对应指针
 * 4. 处理剩余元素
 * 
 * 时间复杂度：O(m+n)
 * 空间复杂度：O(m+n)
 */

#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int a[1000], b[1000], result[2000];

    // 读取数组a
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }
    
    // 读取数组b
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // 归并两个有序数组
    int i = 0, j = 0, k = 0;
    
    // 同时遍历两个数组
    while (i < m && j < n) {
        if (a[i] <= b[j]) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }
    
    // 处理a的剩余元素
    while (i < m) {
        result[k++] = a[i++];
    }
    
    // 处理b的剩余元素
    while (j < n) {
        result[k++] = b[j++];
    }
    
    // 输出结果
    for (int i = 0; i < m + n; i++) {
        printf("%d", result[i]);
        if (i < m + n - 1) printf(" ");
    }
    printf("\n");
    
    return 0;
}
