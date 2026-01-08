/**
 * @brief 图案平铺输出
 * 
 * 问题描述：
 * 将给定的6行图案按m×n平铺输出
 * 
 * 算法分析：
 * - 使用字符串数组存储基本图案
 * - 外层微m次，内层每行重复n次
 * - 时间复杂度：O(m×n)
 * - 空间复杂度：O(1)
 * 
 * 实现要点：
 * 使用#define定义图案模板，循环输出
 */

#include <stdio.h>
#define mod1 "--**-**--"
#define mod2 "-*--*--*-"
#define mod3 "-*-----*-"
#define mod4 "--*---*--"
#define mod5 "---*-*---"
#define mod6 "----*----"

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    if (m < 1 || m > 5 || n < 1 || n > 5) {
        printf("Input Error\n");
        return 0;
    }
    
    const char *mod[6] = {mod1, mod2, mod3, mod4, mod5, mod6};
    
    // 外层循环：输出m个图案块
    for (int block = 0; block < m; block++) {
        // 每个块有6行
        for (int pic = 0; pic < 6; pic++) {
            // 每行重复输出n次图案
            for (int j = 0; j < n; j++) {
                printf("%s", mod[pic]);
            }
            printf("\n");
        }
    }

    return 0;
}