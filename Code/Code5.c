#include <stdio.h>
void main()
{
    int money;
    printf("请输入金额（元）:");
    scanf("%d",&money);
    
    if (money>=100)
    {
    int change=money-100;
    
    printf("找您%d元。\n",change);
    }

    else
    {
        printf("金额不足100元，无法购买。\n");
    }
}