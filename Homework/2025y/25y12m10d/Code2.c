/**
 * @brief 出勤记录判断
 * 
 * 问题描述：
 * 判断学生是否可以获得出勤奖励
 * 条件：缺勤A < 2次 且 无连续3次及以上迟到L
 * 
 * 算法分析：
 * - 遍历字符串统计A的数量
 * - 检查是否存在连续3个L
 * - 满足条件输出1，否则输出0
 * - 时间复杂度：O(n)
 * - 空间复杂度：O(1)
 * 
 * 优化点：
 * 一次遍历同时检查两个条件，提前退出
 */
#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    scanf("%s", s);

    int q = 0;  // q为减分次数
    int len = strlen(s);

    // 一次遍历统计违反条件的情况
    for (int i = 0; i < len; i++) {
        if (s[i] == 'A') {
            // 缺勤一次扣1分
            q++;
        } else if (s[i] == 'L' && s[i + 1] == 'L' && s[i + 2] == 'L') {
            // 连续3次迟到，加2分(总共-2)，然后break
            q = q + 2;
            break;
        } else if (q >= 2) {
            // 提前退出：已有2次缺勤
            break;
        }
    }

    // 输出结果：扣分少于2则可以获奖
    if (q == 0 || q == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
