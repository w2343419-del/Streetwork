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
 * @brief 检测字符串S2在S1中的对称出现，并输出最大对称间隔
 * 
 * 算法思路：
 * 1. 生成S2的反串
 * 2. 在S1中从左向右找S2的第一次出现位置
 * 3. 在S1中从右向左找S2反串的最后一次出现位置
 * 4. 计算间隔 = S2反串起始位置 - (S2起始位置 + S2长度)
 * 
 * 对称间隔定义：
 * S2正串结束位置到S2反串开始位置之间的距离
 * 
 * 时间复杂度：O(len1 * len2)
 * 空间复杂度：O(len2)
 */

#include <stdio.h>
#include <string.h>

int main() {
    char S1[301], S2[11];
    scanf("%s %s", S1, S2);

    int len1 = strlen(S1);
    int len2 = strlen(S2);
    
    // 生成S2的反串
    char S2_rev[11];
    for (int i = 0; i < len2; i++) {
        S2_rev[i] = S2[len2 - i - 1];
    }
    S2_rev[len2] = '\0';

    int pos_S2 = -1, pos_S2_rev = -1;

    // 从左向右找S2的第一次出现
    for (int i = 0; i <= len1 - len2; i++) {
        if (strncmp(&S1[i], S2, len2) == 0) {
            pos_S2 = i;
            break;
        }
    }

    // 从右向左找S2反串的最后一次出现
    for (int j = len1 - len2; j >= 0; j--) {
        if (strncmp(&S1[j], S2_rev, len2) == 0) {
            pos_S2_rev = j;
            break;
        }
    }

    // 检查是否找到对称出现（S2正串必须在反串前面）
    if (pos_S2 != -1 && pos_S2_rev != -1 && pos_S2_rev > pos_S2) {
        // 计算对称间隔：反串起始位置 - 正串结束位置
        printf("%d\n", pos_S2_rev - (pos_S2 + len2));
    } else {
        printf("no\n");
    }
    return 0;
}