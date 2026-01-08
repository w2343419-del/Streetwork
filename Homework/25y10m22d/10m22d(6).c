/* 描述

 

输入一个字符，判断是哪类字符

 

输入

 

第1行是一个整数n，表示随后有n组数据。

每组数据占一行，包含一个字符。

 

输出

 

对于每一组数据，

若该字符是数字，则输出“number”；

若该字符是字母，则输出“letter”

否则输出“else”。

 

样例

 

输入

输出

3

1

a

+



number

letter

else
*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    getchar();
    

    for (int i=0; i<n; i++){
        char ch;
        scanf("%c",&ch);
        
        if (ch>='0' && ch <= '9'){
            printf("number\n");
        }

        else if ((ch>='a' && ch <= 'z') || (ch>='A' && ch <= 'Z')){
            printf("letter\n");
        }

        else{
            printf("else\n");
        }
        
        getchar();
    
    }
    
    return 0;
}