/*输入n个整数，计算它们的平均值，保留小数点后两位。注意：输入可能是无效整数，表示为n/a。在计算平均值时，先排除掉无效整数。

输入
每个输入包含一个测试用例，第1行输入n (1≤n≤100)；第2行输入n个整数，之间用空格分隔。

输出
平均值，保留小数点后两位。如果输入全为n/a，则输出n/a

样例
输入

6
1 2 3 n/a 5 6
输出

3.40*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    char str[101][10];
    int count = 0, sum = 0;
    double res = 0.00;

    for (int i = 0; i < n; i++) {
        scanf("%s", str[i]);
    }

    for (int i = 0; i < n; i++) {
        if (strcmp(str[i], "n/a") == 0) {
            continue;
        } else {
            sum += atoi(str[i]);
            count++;
        }
    }
   
    if (count == 0) {
        printf("n/a\n");
    } else {
        res = (double)sum / count;
        printf("%.2f\n", res);
    }
    
    return 0;
}