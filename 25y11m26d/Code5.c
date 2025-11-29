/*m（m>3）个人围成一圈，从第一个人开始顺序报数1,2,3,1,2,3，…凡报到3的人退出圈子， 请问剩下的最后一个人最开始排在第几个？
输入
第一行是一个整数n，表示一共有n组测试用例；
下面一共有n组输入，每组输入为一个正整数，表示本组测试有多少人

输出
对于每一组输入数据，输出最后剩下那个人在一开始的队伍里排第几

样例
输入
2
4
10

输出
1
4

提示
当最后只剩下两个人A、B时，假设A先报1，那么B报2，然后A再报3，A出圈，最后剩下的就是B。*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        int p[m];
        int c = 0, r = m;
        for (int j = 0; j < m; j++) {
            p[j] = j + 1;
        }
        
        while (r > 1) {
            int out = (c + 2) % r;            
            for (int j = out; j < r - 1; j++) {
                p[j] = p[j + 1];
            }
            r--;
            c = out % r;
        }
        
        printf("%d\n", p[0]);
    }
    return 0;
}