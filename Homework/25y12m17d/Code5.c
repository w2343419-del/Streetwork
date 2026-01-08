/**
 * @brief 统计出现次数最多的英文单词
 * 
 * 问题描述：
 * 统计文本中出现最多的单词，不区分大小写
 * 
 * 算法分析：
 * 1. 逐个读取字符，提取单词（非字母为分隔符）
 * 2. 转为小写后统计每个单词出现次数
 * 3. 找出最大频次，多个时取字典序最大的
 * - 时间复杂度：O(n×m)，n为单词数，m为平均长度
 * - 空间复杂度：O(n×m)
 * 
 * 优化点：
 * 可使用哈希表优化单词查找
 */

/*统计一段文本中出现次数最多的英文单词。单词不区分大小写，即Hello和hello表示同一个单词。
单词和单词之间由一个或多个非字母字符隔开。

提示
如果用getchar()或者scanf()函数读入数据，那么当返回EOF时表示已经读取到文件末尾。
如果用fgets()函数读入数据，那么返回NULL时表示已经读取到文件末尾。*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct word {
    char word[51];
    int count;
} words[10000]; //存储单词及其出现次数

int total = 0, best = -1; //total记录不同单词数量，best记录出现次数最多的单词索引

void process(char *s) {
    if (!*s) return;
    int i = 0;
    for (; i < total; i++) {
        if (!strcmp(words[i].word, s)) break;
    }
    if (i == total) {
        strcpy(words[total].word, s);
        words[total].count = 0;
        total++;
    }
    words[i].count++;

    if (best == -1 || words[i].count > words[best].count || 
       (words[i].count == words[best].count && strcmp(words[i].word, words[best].word) > 0)) {
        best = i;
    }
} //处理单词，更新统计信息

int main() {
    char temp[51];
    int c, len = 0;

    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (len < 50) temp[len++] = (char)tolower(c);
        } else if (len > 0) {
            temp[len] = '\0';
            process(temp);
            len = 0;
        }
    }
    temp[len] = '\0';
    process(temp);

    if (best != -1) printf("%s %d\n", words[best].word, words[best].count);
    return 0;
} //主函数