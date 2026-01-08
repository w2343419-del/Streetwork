/**
 * @brief 压缩字符串中的连续空白字符
 * 
 * 问题描述：
 * 将字符串中所有连续的空白字符（空格、制表符、换行、回车）压缩为单个空格
 * 删除字符串开头的所有空白
 * 
 * 算法分析：
 * - 方法：双指针法，一个读取一个写入
 * - 步骤1：跳过开头所有空白
 * - 步骤2：遇到空白时跳过连续空白，仅保留一个
 * - 步骤3：非空白字符直接复制
 * - 时间复杂度：O(n)，n为字符串长度
 * - 空间复杂度：O(1)，原地修改
 * 
 * 优化点：
 * - 使用isspace()判断空白字符更简洁
 */
#include <stdio.h>

int main() {
    char str[1001];  // 输入字符串
    int len = 0;  // 字符串长度
    char c;
    
    // 读取输入（直到EOF）
    while ((c = getchar()) != EOF && len < 1000) {
        str[len++] = c;
    }
    str[len] = '\0';
    
    int read_pos = 0;  // 读取位置
    int write_pos = 0;  // 写入位置
    
    // 跳过开头的所有空白字符
    while (str[read_pos] == ' ' || str[read_pos] == '\t' || 
           str[read_pos] == '\n' || str[read_pos] == '\r') {
        read_pos++;
    }
    
    // 处理剩余字符
    while (str[read_pos] != '\0') {
        // 如果是空白字符
        if (str[read_pos] == ' ' || str[read_pos] == '\t' || 
            str[read_pos] == '\n' || str[read_pos] == '\r') {
            // 跳过所有连续的空白
            while (str[read_pos] == ' ' || str[read_pos] == '\t' || 
                   str[read_pos] == '\n' || str[read_pos] == '\r') {
                read_pos++;
            }
            // 如果后面还有字符，添加一个空格
            if (str[read_pos] != '\0') {
                str[write_pos++] = ' ';
            }
        }
        // 非空白字符直接复制
        else {
            str[write_pos++] = str[read_pos++];
        }
    }
    str[write_pos] = '\0';
    
    // 输出处理后的字符串
    for (int k = 0; str[k] != '\0'; k++) {
        putchar(str[k]);
    }
    putchar('\n');
    
    return 0;
}