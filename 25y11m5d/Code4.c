/*描述

 

输入一个正整数（奇数），按要求打印菱形。要求，第一行打印1个*，第二行打印3个*，每行等差递增直到输出n个*，之后每行递减输出，直到输出1个*。注意：所有*构成一个菱形的形状,即菱形本身靠中轴线对齐。（注意本题的输出格式）

        

输入

 

第1行是一个整数n，表示随后有n组数据。每组数据占一行。

 

输出

 

若n不符合要求，输出error；若n符合要求，首先输出print，然后换行打印菱形，并换行。注意：菱形最长的一排*靠左边，无空格。

 

样例

 

输入

输出

1

5

print

  *

 ***

*****

 ***

  *
*/
#include <stdio.h>
int main(){
    int n, a;
    scanf("%d", &n);
    
    for( int i = 1; i <= n; i++){
        scanf("%d", &a);
        if (a % 2 == 0) {
            printf("error");
        } else {
            printf("print\n");
            for (int i = 1; i <= a; i += 2) {
                for (int j = 1; j <= (a - i) / 2; j++){
                    printf(" ");
                }
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
            for (int i = a - 2; i >= 1; i -= 2) {
                for (int j = 1; j <= (a - i) / 2; j++){
                    printf(" ");
                }
                for (int j = 1; j <= i; j++) {
                    printf("*");
                }
                printf("\n");
            }
        }
    }
    return 0;
}
   