/*键盘王国里潜伏着一群“捣蛋子串”。
输入任何原文，只要里面出现了指定的捣蛋子串，就必须把它全部挖掉！
挖干净后，把剩下的字符重新拼成“净化文本”输出。
如果原文被挖成空串，也要输出 null ，表示王国已彻底清净。
注意：子串不会重叠。

输入
第一行输入字符串 s ， s 的长度 ≤1000，可能含空格。
第二行输入待查找的子串 k，k 的长度 ≤10，不含空格。

输出
删除子串后的字符串， 如果字符串为空串则输出null。

样例
输入1
I love apple pie and apple jam!
apple

输出1
I love  pie and  jam!

输入2
appleapple
apple

输出2
null*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1001];
    char a[11];

    fgets(s, 1001, stdin);
    scanf("%s", a);

    int len1 = strlen(s);
    int len2 = strlen(a);
    
    if (s[len1-1] == '\n') {
        s[len1-1] = '\0';
        len1--;
    }

    int i = 0;

    while (i < len1) {
        int j = 0;

        while (j < len2 && s[i+j] == a[j]) {
            j++;
        }
        
        if (j == len2) {
            for (int k = i; k < len1 - len2; k++) {
                s[k] = s[k + len2];
            }
            s[len1 - len2] = '\0';
            len1 -= len2;
        } else {
            i++;
        }
    }
    
    if (len1 == 0) {
        printf("null\n");
    } else {
        printf("%s\n", s);
    }
    
    return 0;
}
