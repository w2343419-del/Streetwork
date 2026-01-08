/**
 * @brief 计算有效整数的平均值
 * 
 * 算法思路：
 * 1. 读取所有输入，分别作为字符串存储
 * 2. 过滤掉"n/a"，累加有效整数
 * 3. 计算有效整数的平均值
 * 4. 如果全为n/a，输出n/a\n * 时间复杂度：O(n)
 * 空间复杂度：O(n)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char str[101][10];
    int count = 0, sum = 0;
    
    // 读取所有数据
    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }
    
    // 统计有效数据
    for (int i = 0; i < n; i++) {
        if (strcmp(str[i], "n/a") != 0) {
            sum += atoi(str[i]);
            count++;
        }
    }
    
    // 输出结果
    if (count == 0) {
        printf("n/a\n");
    } else {
        double average = (double)sum / count;
        printf("%.2f\n", average);
    }
    
    return 0;
}
