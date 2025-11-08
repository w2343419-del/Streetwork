/*描述
都听说过“韩信点兵，多多益善”这个成语，韩信才智过人，从不直接清点人数。
只要让士兵 3 人一排，5 人一排，7 人一排的变换队形，查看队尾人数便能清点队伍总人数。
输入
第1行是一个整数 n，表示随后有 n 组数据。
每组数据占一行，包括三种队形的队尾人数a,b,c，用空格隔开。已知队伍总人数不小于 
10，不大于100。

输出
对每组数据，输出相应的队伍总人数，并换行。不存在则输出 Impossible，并换行。

样例1
输入

2
1 2 3
2 3 2
输出

52
23

样例2
输入
3
1 1 2
2 4 6
2 3 6

输出
16
Impossible
83*/
#include <stdio.h>
int main() {
    int n, a, b, c, i, sum;
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d %d %d", &a, &b, &c);
        int bOK = 0;
        
        for(sum = 10; sum < 100; sum++){
            if (sum % 3 == a && sum % 5 == b && sum % 7 == c){
                printf("%d\n", sum);
                bOK = 1;
                break;
            } 
        } if(bOK == 0) {
        printf("Impossible\n");
        }
    }
    return 0;

}