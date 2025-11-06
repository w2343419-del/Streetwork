/*描述
输入一个十进制正整数 m（1 ≤ m ≤ 10⁹）和一个指定数字 n（0 ≤ n ≤6），
统计 m 在 7 进制表示 中出现了多少次数字 n。
输入
一行，两个用空格分隔的整数 m 和 n。
输出
一个整数，表示 m 的 7 进制表示中数字 n 的出现次数。
样例
输入
100 2
输出
2
输入
10
输出
0*/
#include <stdio.h>
int main(){
    int m, n;
    int b;
    int num = 0;
    scanf("%d %d", &m, &n);
    
    while (m != 0) {
        b = m % 7;
        m = m / 7;
        
        if (b == n) {
            num++;
        }
    }
    printf("%d", num);
}