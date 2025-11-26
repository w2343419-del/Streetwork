/*求两个字符串的最长相同后缀，即从最后一个字符起，最长的相等子串
输入
两个非空字符串

输出
最长相同后缀。不存在相同后缀则输出null

样例1
输入	
abcdefg	
dadcefg	

输出
efg

样例2
输入	
abcdefg	
1234567

输出
null*/

#include <stdio.h>
#include <string.h>

int main() {
    char a[99999], b[99999];
    scanf("%s", a);
    scanf("%s", b);

    int len1 = strlen(a);
    int len2 = strlen(b);
    int i = len1 - 1;
    int j = len2 - 1;
    int count = 0;

    while (i >= 0 && j >= 0 && a[i] == b[j]) {
        count++;
        i--;
        j--;
    }

    if (count == 0) {
        printf("null\n");
    } else {
        for (int k = len1 - count; k < len1; k++) {
            printf("%c", a[k]);
        }
        printf("\n");
    }

    return 0;
}