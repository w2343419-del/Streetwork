/*统计一段文本中出现次数最多的英文单词。单词不区分大小写，即Hello和hello表示同一个单词。
单词和单词之间由一个或多个非字母字符隔开。

输入
输入数据为一段文本，可能包含若干行，直到文件末尾(EOF)为止。即只有一组测试用例。

输出
输出该段文本中出现最多的单词(全变换成小写字母)，及该单词出现的次数，中间用空格隔开。
如果出现次数最多的单词有多个，输出字典序最大(全转换成小写字母比较)的那个。

样例1
输入
Is this a   very hard problem?
No, it is not!

输出
is 2

样例2
输入
I like   computer.   I like Computer Science.
I like School   of Computer Science.
I like   Sichuan University.

输出
like 4

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