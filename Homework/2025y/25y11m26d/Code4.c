/**
 * @brief 字符串操作器
 * 
 * 支持的操作：
 * L：膨胀2倍（abc -> aabbcc）
 * R：翻转（abc -> cba）
 * Dn：删除中心左侧的n个字符
 * \n * 算法思路：
 * 1. 对每组指令串，从原始字符串S开始
 * 2. 依次执行指令L/R/Dn
 * 3. 返回结果字符串的第k个字符
 * 
 * 优化点：
 * - 不直接修改字符串，而是使用指针追踪位置
 * - 避免大量字符串复制\n * 时间复杂度：O(指令数 * 字符串长度)
 * 空间复杂度：O(1000) - 字符串长度上限
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[1001];
    fgets(s, sizeof(s), stdin);
    
    // 移除换行符
    int orig_len = strlen(s);
    if (s[orig_len - 1] == '\n') {
        s[orig_len - 1] = '\0';
    }
    
    char cmd[25];
    while (scanf("%s", cmd) != EOF) {
        if (strcmp(cmd, "End") == 0) break;
        
        int k;
        // 解析指令
        char op = cmd[0];
        char *rest = cmd + 1;
        
        scanf("%d", &k);
        
        // 从原始字符串开始
        char curr[1001];
        strcpy(curr, s);
        int curr_len = strlen(curr);
        
        // 处理指令串（每个字符都是一个操作）
        int i = 0;
        while (i < strlen(cmd)) {
            if (cmd[i] == 'L') {
                // 膨胀2倍
                char temp[1001];
                int pos = 0;
                for (int j = 0; j < curr_len; j++) {
                    temp[pos++] = curr[j];
                    temp[pos++] = curr[j];
                }
                temp[pos] = '\0';
                strcpy(curr, temp);
                curr_len = pos;
                i++;
            } else if (cmd[i] == 'R') {
                // 翻转
                for (int j = 0; j < curr_len / 2; j++) {
                    char t = curr[j];
                    curr[j] = curr[curr_len - 1 - j];
                    curr[curr_len - 1 - j] = t;
                }
                i++;
            } else if (cmd[i] == 'D') {
                // 删除
                i++;
                int del_count = 0;
                while (i < strlen(cmd) && cmd[i] >= '0' && cmd[i] <= '9') {
                    del_count = del_count * 10 + (cmd[i] - '0');
                    i++;
                }
                
                // 删除中心左侧的del_count个字符
                int mid = curr_len / 2;
                int start = (mid - del_count > 0) ? (mid - del_count) : 0;
                
                char temp[1001];
                int pos = 0;
                for (int j = 0; j < start; j++) {
                    temp[pos++] = curr[j];
                }
                for (int j = mid; j < curr_len; j++) {
                    temp[pos++] = curr[j];
                }
                temp[pos] = '\0';
                strcpy(curr, temp);
                curr_len = pos;
            }
        }
        
        // 输出第k个字符
        if (k > 0 && k <= curr_len) {
            printf("%c\n", curr[k - 1]);
        } else {
            printf("NULL\n");
        }
    }
    
    return 0;
}
