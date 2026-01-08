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
    char c[1001];
    int i = 0;
    
    char ch;
    while ((ch = getchar()) != '\n' && i < 1000) {
        c[i] = ch;
        i++;
    }
    c[i] = '\0';
    
    char vowels[1001];
    int vowel_count = 0;
    
    int j = 0;
    while (j < i) {
        if (c[j] == 'a' || c[j] == 'e' || c[j] == 'i' || c[j] == 'o' || c[j] == 'u') {
            vowels[vowel_count] = c[j];
            vowel_count++;
        } else if (c[j] == 'A' || c[j] == 'E' || c[j] == 'I' || c[j] == 'O' || c[j] == 'U') {
            vowels[vowel_count] = c[j] + 32;
            vowel_count++;
        }
        j++;
    }

    if ( vowel_count == 0 ){
        printf("0\n");
    } else {
        for ( int k = 0; k < vowel_count; k++) {
            if (k > 0) printf("-");
            printf("%c", vowels[k]);
        }
        printf ("-%d", vowel_count);
    }
    return 0;
}


