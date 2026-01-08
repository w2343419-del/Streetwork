/*给定一个整型数组，统计不同的元素的个数。

输入
每组输入占一行，每先给出正整数 n (n≤30)，随后是 n 个整数 ai(−100≤ai≤100)，以空格分隔。

输出
输出占一行，以回车结束。输出不同的元素的个数。

样例1
输入
4 3 -5 2 8

输出
4*/

#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);

    int i;
    int count[201] = {0};
    int arr[201] = {0};

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int l = 0; l < n; l++) {
        for (int j = l + 1; j < n; j++) {
            if (arr[l] == arr[j]) {
                count[l] = 1;
            }
        }
    }
        
    int num = 0;

    for (int k = 0; k < n; k++) {
        if (count[k] == 0) {
            num++;
        }
    }
    
    printf("%d\n", num);
    return 0;
}