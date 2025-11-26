/*
输入一个正整数(32位int可以存放下)，请判断他是否为回文数。
所谓回文数：类似1234321，123321等这样，其十进制表示下，顺序和逆序相同的整数为回文数。

输入
第一行为正整数 n，表示数据组数。
随后 n 行，每行包含一个正整数 mi
​。

输出
对每个 mi，如果是回文数，输出Yes，否则输出No，并换行。

样例
输入

3
1231
12321
12345
输出

No
Yes
No*/
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int num;
        char str[40];
        int len;
        int a = 1;
        
        scanf("%d", &num);
        sprintf(str, "%d", num);
        len = strlen(str);
                
        for (int j = 0; j < len / 2; j++) {
            if (str[j] != str[len-1-j]) {
                a = 0;
                break;
            }
        }
        
        if (a) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}