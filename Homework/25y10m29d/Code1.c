/*
描述
输入三角形的3条边长， 判断三角形是否是直角三角形。

输入
第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含3个整数代表3条边长(每个整数的平方能够用32位整数表示)，用空格分隔。

输出
每组输出占一行，如果是直角三角形输出Yes，不是则输出No。

样例
输入

2
3 4 5   
3 5 7
输出

Yes
No
*/
#include <stdio.h>
#include <math.h>
int main() {
    int n;
    int a, b, c, max, mid, min;
    double d, e;
    scanf ("%d", &n);
    
    for ( int i = 0; i<n; i++ ) {
        scanf ("%d %d %d", &a, &b, &c);
    
        
        if( a <= 0 || b <= 0 || c <= 0 ) {
            printf ("No\n");
        } else if (a+b <= c || a+c <= b || b+c <= a) {
            printf ("No\n");
        } else {
            if (a >= b) {
                max = a; min = b;
                
                if (c >= max) {
                    max = c; mid = a; min = b;
                } else if (c <= min) {
                    max = a; mid = b; min = c;
                } else {
                    max = a; mid = c; min = b;
                }
            } else {
                max = b; min = a;

                if (c >= max) {
                    max = c; mid = b; min = a;
                } else if (c <= min) {
                    max = b; mid = a; min = c;
                } else {
                    max = b; mid = c; min = a;
                }
            }

            d = pow ( max, 2 );
            e = pow ( min, 2 ) + pow ( mid, 2 );

            if ( d == e ) {
                printf ("Yes\n");
            } else {
                printf ("No\n");
            }
        }
    }
    
    return 0;
}