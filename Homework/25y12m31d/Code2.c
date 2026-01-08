/**
 * @brief 字符串对称检测 - 最大间隔计算
 * 
 * 问题描述：
 * 检测S2是否在S1中对称出现，并输出最大对称间隔
 * 对称定义：S2正串在S2反串前面出现
 * 间隔定义：S2正串结束位置到S2反串开始位置的距离
 * 
 * 算法分析：
 * 1. 生成S2的反串reverse_S2
 * 2. 遍历S1，找到所有S2出现的位置
 * 3. 对于每个S2位置i，在其后查找reverse_S2的位置j
 * 4. 计算间隔 = j - (i + len(S2))
 * 5. 取所有间隔的最大值
 * 
 * 特殊情况：
 * - S2为回文：正串和反串相同，需特殊处理
 * - 重叠情况：间隔可能为负数
 * 
 * 时间复杂度：O(n×m) - n为S1长度(≤300)，m为S2长度(≤10)
 * 空间复杂度：O(m) - 存储S2反串
 * 
 * 优化点：
 * - 使用strstr进行字符串匹配，简化代码
 * - 提前处理回文情况，避免重复计算
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
