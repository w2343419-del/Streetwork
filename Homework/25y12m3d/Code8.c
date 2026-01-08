/*m个人围成一圈，从第一个人开始顺序报数1，2，3，4，5，6，7，8…报到7的倍数或者含有7的数的人退出，请问剩下的最后一个人最开始排在第几个？

输入
第一行是一个整数n，表示一共有n组测试用例。下面一共有n组输入，每组输入为一个正整数，表示本组测试有多少人（7<m<1000）。

输出
对于每一组输入数据，输出最后剩下那个人在一开始的队伍里排第几。

样例
输入
2
10
20

输出
10
5
*/

#include <stdio.h>

int main() { 
    int p;
    scanf("%d", &p);
    
    for (int i = 0; i < p; i++) {
        int m; 
        scanf("%d", &m); 

        int s[1000]; 
        int number_1 = 1; 
        
        while (number_1 <= m) { 
            s[number_1] = number_1; 
            number_1++; 
        } 
    
        int count = 1;
        int remaining = m;
        int position = 1;

        while (remaining > 1) {
            if (s[position] != 0) {
                int a = 0;
                if (count % 7 == 0) {
                    a = 1;
                }
                
                int temp = count;
                while (temp > 0) {
                    if (temp % 10 == 7) {
                        a = 1;
                        break;
                    }
                    temp /= 10;
                }
                
                if (a == 1) {
                    s[position] = 0;
                    remaining--;
                }
                count++;
            }

            position++;
            if (position > m) {
                position = 1;
            }
        }

        for (int j = 1; j <= m; j++) {
            if (s[j] != 0) {
                printf("%d\n", s[j]);
                break;
            }
        }
    }
    
    return 0;
}