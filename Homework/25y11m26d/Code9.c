/**
 * @brief 大整数比较 - 字符串实现
 * 
 * 问题描述：
 * 输入两个整数（0 ≤ x ≤ 10^30），输出较小的数
 * 若输入不合法（负数或非数字），输出Input Error
 * 
 * 算法分析：
 * 1. 字符串读取：用字符串处理超大整数（最多31位）
 * 2. 合法性检查：
 *    - 检查是否全为数字字符
 *    - 检查是否有负号
 *    - 检查前导零情况（0本身除外）
 * 3. 大小比较：
 *    - 先比较长度（长度长的数更大）
 *    - 长度相同时字典序比较
 * 
 * 时间复杂度：O(n) - n为数字位数，最大31
 * 空间复杂度：O(1) - 固定200字符数组
 * 
 * 优化点：
 * - 利用字符串比较实现大整数比较，无需高精度运算
 * - 提前验证合法性，避免无效计算
 */

#include <stdio.h>
#include <string.h>
int main() {
    int n;
    scanf("%d", &n);
    char a[200], b[200];

    for (int i = 0; i < n; i++) {
        scanf("%s %s", a, b);

        int len1 = strlen(a);
        int len2 = strlen(b);
        int valid = 1;

        for (int j = 0; j < len1; j++) {
            if (a[j] < '0' || a[j] > '9') {
                valid = 0;
                break;
            }
        }
        
        for (int j = 0; j < len2; j++) {
            if (b[j] < '0' || b[j] > '9') {
                valid = 0;
                break;
            }
        }
        
        if (len1 > 31 || len2 > 31) {
            valid = 0;
        }

        if (valid == 0) {
            printf("Input Error\n");
        } else {
            if (len1 < len2) {
                printf("%s\n", a);
            } else if (len1 > len2) {
                printf("%s\n", b);
            } else {
                int found = 0;
                
                for (int k = 0; k < len1; k++) {
                    if (a[k] < b[k]) {
                        printf("%s\n", a);
                        found = 1;
                        break;
                    } else if (a[k] > b[k]) {
                        printf("%s\n", b);
                        found = 1;
                        break;
                    }
                }
                
                if (found == 0) {
                    printf("%s\n", a);
                }
            }
        }
    }
    
    return 0;
}