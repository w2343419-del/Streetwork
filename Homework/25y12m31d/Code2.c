/*有两个字符串S1,S2，请编程检测S2是否在S1中对称出现(S2正串一定要在S2反串前面)，并输出最大对称间隔。
例如：
S1 = fabcdhba, S2 = ab，其中，ab...ba称为S2在S1中对称出现了1次，S2正串为ab，S2反串为ba，对称间隔为3。
S1 = abcdhbaghba, S2=ab，其中，ab...ba..ba称为S2在S1中对称出现了2次，对称间隔为3和7。
如果S2对称出现多次，则输出最大间隔。
注意：如果S2和S2的反串有部分重叠，那么间隔是负数。

输入
输入两个字符串S1,S2，以空格分开，字符串内部没有空格。
S1长度不超过300，S2的长度不超过10。

输出
输出S2最大对称间隔。
如果没有对称出现的S2出现，则输出no。

样例
输入
abcdhba abcd

输出
no

输入
abcdhbaghba ab

输出
7*/

/**
 * @brief 字符串对称检测 - 增强版
 * 
 * 算法思路：
 * 1. 生成S2的反串
 * 2. 检查S2是否为回文（若是回文则无法对称出现）
 * 3. 遍历S1，找到所有S2出现的位置
 * 4. 对于每个S2位置，向后查找S2反串
 * 5. 计算最大间隔
 * 
 * 优化点：
 * - 提前检查回文情况
 * - 清晰的变量命名
 * - 优化查找逻辑
 * 
 * 时间复杂度：O(len1 * len2)
 * 空间复杂度：O(len2)
 */

#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    char s1[301], s2[11];
    scanf("%s %s", s1, s2);

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // 生成S2的反串
    char s2_rev[11];
    for (int i = 0; i < len2; i++) {
        s2_rev[i] = s2[len2 - 1 - i];
    }
    s2_rev[len2] = '\0';

    // 如果S2是回文串，则无法对称出现
    if (strcmp(s2, s2_rev) == 0) {
        printf("no\n");
        return 0;
    }

    int max_distance = INT_MIN;
    int found = 0;

    // 遍历所有可能的S2正串位置
    for (int i = 0; i <= len1 - len2; i++) {
        if (strncmp(&s1[i], s2, len2) == 0) {
            // 找到S2正串，向后寻找反串
            for (int j = i + len2 - 1; j <= len1 - len2; j++) {
                if (strncmp(&s1[j], s2_rev, len2) == 0) {
                    // 计算间隔
                    int distance = j - (i + len2);
                    if (distance > max_distance) {
                        max_distance = distance;
                        found = 1;
                    }
                }
            }
        }
    }

    if (found) {
        printf("%d\n", max_distance);
    } else {
        printf("no\n");
    }
    
    return 0;
}
    for (int i = 0; i < len2; i++) {
        s2_rev[i] = s2[len2 - 1 - i];
    }
    s2_rev[len2] = '\0';

    // 如果S2是回文串，则无法对称出现（正串和反串相同）
    if (strcmp(s2, s2_rev) == 0) {
        printf("no\n");
        return 0;
    }

    int max_distance = INT_MIN;
    int found = 0;

    // 遍历所有可能的S2正串位置
    for (int i = 0; i <= len1 - len2; i++) {
        if (strncmp(&s1[i], s2, len2) == 0) {
            // 找到S2正串，向后寻找反串
            // 反串必须在正串结束之后或有重叠（允许负距离）
            for (int j = i + len2 - 1; j <= len1 - len2; j++) {
                if (strncmp(&s1[j], s2_rev, len2) == 0) {
                    // 计算间隔：反串起始位置 - 正串结束位置
                    int distance = j - (i + len2);
                    if (distance > max_distance) {
                        max_distance = distance;
                        found = 1;
                    }
                }
            }
        }
    }

    if (found) {
        printf("%d\n", max_distance);
    } else {
        printf("no\n");
    }
    
    return 0;
}
