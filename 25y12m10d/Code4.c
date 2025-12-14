/*想象你手里握着一张“宝藏密码条”——它原本由字母、数字和横线“-”胡乱拼接而成，
像被顽皮的小精灵撕成了长短不一的小段。
现在，你要当一次“密码工匠”，把它重新雕刻成闪闪发光的“圣铠密钥”：

每一组包含 k 个字符
两组之间用破折号 - 分隔
所有字母转换为大写
如果最后一组不足 k 个字符，则用 ‘=’ 补足。

输入
先输入整数 k，再输入字符串 s ，中间用空格分隔。
整数 1≤k≤10 。
字符串 s 仅包含字母、数字和破折号， 长度不超过 100 。

输出
输出格式化后的字符串。

样例

输入1
4 5F3Z-2e-9-w

输出1
5F3Z-2E9W

输入2
8 2-5g-3-J

输出2
25G3J===

输入3
5 5F3Z-2e-9-w---

输出3
5F3Z2-E9W==*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int k;
    char s[99999];
    scanf("%d %s", &k, s);

    int pos = 0;
    
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] != '-') {
            s[pos++] = toupper(s[i]);
        }
    }
    s[pos] = '\0';

    int len = pos;
    
    while (len % k != 0) {
        s[len++] = '=';
    }
    s[len] = '\0';

    for (int i = 0; i < len; i++) {
        if (i > 0 && i % k == 0) {
            printf("-");
        }
        printf("%c", s[i]);
    }
    
    return 0;
}