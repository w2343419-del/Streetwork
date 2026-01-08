/**
 * @brief 字符串指令序列模拟
 * 
 * 问题描述：
 * 给定初始字符串S和多条指令串，对S执行指令后查询第k个字符
 * 指令：
 *  - L：字符膨胀2倍，如abc→aabbcc
 *  - R：反转字符串
 *  - Dn：删除中心左侧n个字符，若不足则删左侧全部
 * 结束指令为End
 * 
 * 算法分析：
 * - 对每条指令串从左到右模拟
 * - L：生成新串，长度最多×2，但整体约束长度≤1000
 * - R：原地反转
 * - Dn：计算中心左侧位置，截取右侧子串
 * - 完成后输出第k个字符，超界输出NULL
 * 
 * 时间复杂度：O(lenS × lenInstr)（L操作可能倍增，但有长度上限1000）
 * 空间复杂度：O(1000)
 * 
 * 优化点：
 * - 每组指令独立从原串开始，避免状态污染
 * - 严格控制长度上限，防止溢出
 */
/*小白是一个字符操作员，对于给定的一行字符串，他根据输入的指令串对字符串进行操作，指令包括：
L：把字符串膨胀2倍，例如 abc -> aabbcc
R：把字符串进行翻转，例如 abc -> cba
Dn，其中n为一个整数：删除中心左侧的n个字母，如果字符数不够，则删除左侧全部字符，例如
D1：abcde -> acde
D2：abcde -> cde
D1：abcd -> acd
D3：abcd -> cd
请编写程序帮助小白完成他的工作，并计算执行完成指令串后字符串第k(从1开始计)个位置上的字母是什么？

输入
第一行输入字符串S，长度不超过32。其中可能包含空格。
随后若干行，每行为一组指令。
前半部分为指令串，长度不超过16。随后为整数k，中间以空格分隔。
指令End表示结束输入。
可以保证，执行指令过程中的字符串长度不会超过1000。

输出
对每一组指令，按照要求从字符串S开始，依次执行指令后，得到一个字符串，输出该字符串第k个位置上的字符。
如果没有满足条件的字符则输出NULL。
每组指令都在原始字符串上进行操作，每组指令的输出占一行。

样例
输入
abcd
RD2L 3
D3R 20
End

输出
a
NULL

解释
对于第1条指令，abcd -> dcba -> ba -> bbaa，所以第3个字符是a；
对于第2条指令，abcd -> cd -> dc，没有第20个字符，所以结果是NULL。*/

/**
 * @brief 字符串操作模拟器
 * 
 * 算法思路：
 * 1. 读取原始字符串（可能包含空格，使用fgets）
 * 2. 对每组指令：
 *    - 复制原始字符串到工作副本
 *    - 解析并执行每个指令（L/R/Dn）
 *    - 输出第k个字符或NULL
 * 
 * 操作说明：
 * - L操作：每个字符膨胀为两个 (O(n))
 * - R操作：字符串反转 (O(n))
 * - Dn操作：删除中心左侧n个字符 (O(n))
 * 
 * 优化点：
 * - 使用临时缓冲区避免频繁的内存操作
 * - 正确处理字符串长度变化
 * - 边界条件检查
 * 
 * 时间复杂度：O(Q * M * N)，Q为查询数，M为指令长度，N为字符串长度
 * 空间复杂度：O(N)
 */

#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1001      // 最大字符串长度
#define MAX_CMD_LEN 33        // 最大指令长度
#define MAX_TEMP_LEN 2002     // 临时缓冲区（L操作可能翻倍）

/**
 * @brief 执行L操作：字符串膨胀2倍
 * @param str 原字符串
 * @param len 字符串长度的指针
 */
void operation_L(char *str, int *len) {
    char temp[MAX_TEMP_LEN];
    int new_len = (*len) * 2;
    
    // 每个字符复制两次
    for (int i = 0; i < *len; i++) {
        temp[2 * i] = str[i];
        temp[2 * i + 1] = str[i];
    }
    
    // 复制回原字符串
    memcpy(str, temp, new_len);
    *len = new_len;
}

/**
 * @brief 执行R操作：字符串反转
 * @param str 原字符串
 * @param len 字符串长度
 */
void operation_R(char *str, int len) {
    // 双指针反转
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

/**
 * @brief 执行Dn操作：删除中心左侧n个字符
 * @param str 原字符串
 * @param len 字符串长度的指针
 * @param n 要删除的字符数
 */
void operation_D(char *str, int *len, int n) {
    int center = (*len) / 2;
    
    // 计算删除的起始位置和实际删除数量
    int del_start = (center - n < 0) ? 0 : center - n;
    int del_count = center - del_start;
    
    // 将后面的字符向前移动
    int new_len = (*len) - del_count;
    memmove(str + del_start, str + center, new_len - del_start);
    
    *len = new_len;
}

int main() {
    char original[MAX_STR_LEN];
    
    // 读取原始字符串（可能包含空格）
    fgets(original, sizeof(original), stdin);
    
    // 移除换行符
    int original_len = strlen(original);
    if (original[original_len - 1] == '\n') {
        original[original_len - 1] = '\0';
        original_len--;
    }
    
    char command[MAX_CMD_LEN];
    
    // 处理每组指令
    while (scanf("%s", command) == 1) {
        // 检查结束标记
        if (strcmp(command, "End") == 0) {
            break;
        }

        int k;
        scanf("%d", &k);

        // 创建工作副本
        char str[MAX_STR_LEN];
        strcpy(str, original);
        int len = original_len;

        // 执行指令序列
        int cmd_len = strlen(command);
        for (int i = 0; i < cmd_len; i++) {
            if (command[i] == 'L') {
                operation_L(str, &len);
            } 
            else if (command[i] == 'R') {
                operation_R(str, len);
            } 
            else if (command[i] == 'D') {
                // 解析数字n
                i++;
                int n = 0;
                while (i < cmd_len && command[i] >= '0' && command[i] <= '9') {
                    n = n * 10 + (command[i] - '0');
                    i++;
                }
                i--;  // 回退一位，因为for循环会i++
                
                operation_D(str, &len, n);
            }
        }

        // 输出第k个字符
        if (k > len || k <= 0) {
            printf("NULL\n");
        } else {
            printf("%c\n", str[k - 1]);
        }
    }

    return 0;
}
