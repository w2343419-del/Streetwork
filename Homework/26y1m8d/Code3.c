/**
 * @brief 从N个正整数中找出最小的能被3整除的数
 * 
 * 程序从标准输入读取N个正整数，遍历这些数找出其中最小的能被3整除的数。
 * 如果存在能被3整除的数，则输出该最小值；否则输出"Null"。
 * 
 * 时间复杂度: O(N)
 * 空间复杂度: O(1)
 */

#include <stdio.h>

int main() {
    // 读取正整数的个数
    int n;
    scanf("%d", &n);
    
    // 初始化最小值为-1，表示还未找到能被3整除的数
    int min = -1;
    
    // 遍历n个正整数
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        
        // 检查num是否能被3整除，且是当前找到的最小值
        if (num % 3 == 0 && (min == -1 || num < min)) {
            min = num;
        }
    }
    
    // 如果找到能被3整除的数，输出最小值；否则输出"Null"
    if (min != -1) {
        printf("%d\n", min);
    } else {
        printf("Null\n");
    }
    
    return 0;
}
