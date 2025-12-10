/*给定一个字符串 s，找到它的 第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

输入
一行字符串 s (1 <= 长度 <= 100)。

字符串只包含小写字母 ‘a’ 到 ‘z’。

输出
一个整数，表示第一个不重复字符的索引， 索引从0开始，如果不存在返回 -1

样例
输入
aabb

输出
-1

输入
programming

输出
0
*/

#include <stdio.h>
#include <string.h>

int main() {
    char a[101];
    scanf("%s", a);
    
    int len = strlen(a);
    
    for (int i = 0; i < len; i++) {
        int count = 0;
        for (int j = 0; j < len; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        
        if (count == 1) {
            printf("%d\n", i);
            return 0;
        }
    }
    
    printf("-1\n");
    return 0;
}