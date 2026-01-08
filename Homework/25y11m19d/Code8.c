/*输入一个不大于 20 的正整数 n，输出 n 行直角杨辉三角。 
（提示：直角杨辉三角的每一行的第一个数和最后一个数均为 1，其余数字均为其正上方与左上方数字之和） 

输入 
一个不大于 20 的正整数。 

输出 
当输入不符合题意时，输出 Input Error；否则输出输出 n 行直角杨辉三角。 
（注意：每行输出的数字，用英文格式下的逗号两两相隔） 

样例 1 
输入
1                                                   

输出
1,

样例 2 
输入 
4

输出
1,
1,1,
1,2,1,

1,3,3,1,*/
#include <stdio.h>
int main() {
    int n; 
    scanf("%d", &n);
    if (n <= 0 || n > 20) {
        printf("Input Error\n");
        return 0;
    } else {
        int j;
        int a[20][20] = {0};
        for (int i = 0; i < n; i++) {
            for (j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    a[i][j] = 1;
                } else {
                    a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
                }
                printf("%d,", a[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}