/*逆序输出字符串，要求用递归实现。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含一个字符串。

输出
对每组数据，逆序输出字符串，并换行。

样例

输入
3
abcd
1234567
qwertyuiop

输出
dcba
7654321
poiuytrewq

提示
请从标准输入读入数据，将结果输出到标准输出。
输入数据包含多组数据，可以读一组，计算一组，输出一组。*/
#include <stdio.h>

void put(char *str) {
    if (*str == '\0') {
        return ;
    }
    put(str + 1);
    printf("%c", *str);
}

int main() {
    int n; 
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        char str[1000];
        scanf("%s", str);

        put(str);
        printf("\n");
    }
    return 0;
}