/*描述
在整数序列中搜索某数是否存在，并统计在它的右侧有几个比它大的数。如果整数序列中存在多个要查找的值，则统计第一次出现的查找值的位置右侧有几个比查找值大的数。

输入
每个输入包含一个测试用例，第1行输入 n (1≤n≤10)；第2行输入 n 个整数，之间用空格分隔；第三行输入要查找的整数 m。

输出
如果序列中不存在 m，输出none；如果存在，则输出第一个 m 的右侧有几个比 m 大的数。

样例1
输入

4
1 5 3 4
7
输出

none
样例2
输入

5
2 3 4 5 1
3
输出

2*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int a[10];
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    int m;
    scanf("%d", &m);

    int found = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == m) {
            found = 1;
            pos = i;
            break;
        }
    }
    
    if (!found) {
        printf("none\n");
        return 0;
    }
    
    int count = 0;
    for (int j = pos + 1; j < n; j++) {
        if (a[j] > m) {
            count++;
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}