#include <stdio.h>
int main()
{
    int a, b, c, d, e;
    scanf("%d %d", &a, &b);
    scanf("%d %d %d", &c, &d, &e);
    
    if (c == d && d == e)
    {
        if (c == 0)
        {
            printf("一号选手获胜");
            return 0;
        }

        else 
        {
            printf("二号选手获胜");
            return 0;
        }

    } 

    else
    {
        if (a>b)
        {
            printf("一号选手获胜");
            return 0;
        }

        else
        {
            printf("二号选手获胜");
            return 0;
        }
    }

}

