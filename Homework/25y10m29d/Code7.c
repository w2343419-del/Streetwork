/**
 * @brief 统计并输出元音字母
 * 
 * 问题描述：
 * 统计文本中元音字母（A/E/I/O/U，大小写均算）的出现次数
 * 按出现顺序输出这些元音（大写转小写，用"-"连接）
 * 
 * 算法分析：
 * - 方法：字符逐一检测，元音判断并记录
 * - 大写字母ASCII码+32转为小写
 * - 时间复杂度：O(n)，n为字符串长度
 * - 空间复杂度：O(n)，存储元音字母
 * 
 * 优化点：
 * - 使用tolower()函数可以更简洁
 * - 可以用strchr()判断是否为元音
 */

/*描述
输入一段仅由可见 ASCII 字符组成的文本（不包含空格），长度 ≤ 1000。
统计并输出其中元音字母（A、E、I、O、U，大小写均算）的出现次数，同时在同一行按出现顺序输出这些元音字母（大写统一转小写，相邻字母用“-”连接）。
若文本中没有任何元音，则仅输出 0。

输入
一行，一个长度不超过 1000 的可见字符串。

输出
一行，结果格式为：
v1-v2-…-vk-count
其中 count 为总次数；若 count = 0 则仅输出 0。

样例
输入

Hello,World!
输出

e-o-o-3
输入

Rhythm
输出

0*/
#include <stdio.h>
int main () {
    char text[1001];  // 输入文本
    int length = 0;  // 实际长度
    
    // 读取输入字符串（直到换行）
    char ch;
    while ((ch = getchar()) != '\n' && length < 1000) {
        text[length++] = ch;
    }
    text[length] = '\0';
    
    char vowels[1001];  // 存储找到的元音字母
    int vowel_count = 0;  // 元音字母计数
    
    // 遍历文本，检测元音字母
    for (int i = 0; i < length; i++) {
        char c = text[i];
        
        // 检查小写元音
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            vowels[vowel_count++] = c;
        }
        // 检查大写元音，转为小写存储
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            vowels[vowel_count++] = c + 32;  // 大写转小写：'A'+32='a'
        }
    }
    
    // 输出结果
    if (vowel_count == 0) {
        printf("0\n");
    } else {
        // 输出元音字母（用"-"连接）
        for (int k = 0; k < vowel_count; k++) {
            if (k > 0) printf("-");
            printf("%c", vowels[k]);
        }
        // 输出总次数
        printf("-%d\n", vowel_count);
    }
    
    return 0;
}


