/*描述
输入 
3
3 个十进制整数，计算最大值和最小值的差并输出。

输入
输入 
3
3 个十进制整数，范围是 
−
100
∼
100
−100∼100，中间以空格分隔。

输出
输出最大值和最小值的差。

样例
输入

1 2 3
输出

2*/

#include <stdio.h>
int main()
{
    int a,b,c,max,min,minus;
    scanf("%d %d %d", &a, &b, &c);
    if (a>b)
    {
        max=a;
        min=b;
    }

    else 
    {
        max=b;
        min=a;
    }

    if(c>max)
    {
        max=c;
    }

    if(c<min)
    {
        min=c;
    }
    minus=max-min;
    printf("%d", minus);
    return 0;
}
