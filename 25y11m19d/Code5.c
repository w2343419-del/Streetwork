/*描述
输入 n 个整数，找出输入的整数中只出现 2 次的数。

输入
每个输入包含一个测试用例，第1行输入整数 n (1≤n≤20)；第2行输入 n 个整数，之间用空格分隔。

输出
输出只出现2次的整数，存在多个则用空格分隔，按首次出现的顺序输出。如果没有，则输出none。

样例1
输入
5
5 2 3 4 3

输出
3

样例2
输入
6
2 3 3 2 5 6

输出
2 3

样例3
输入
4
3 4 5 6

输出
none*/
#include <stdio.h>
int main() {
    int n, a[20], i, j;
    int freq[1000] = {0}; 
    int found[20];        
    int found_count = 0;
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i] + 500]++; 
    }
    
    for (i = 0; i < n; i++) {
        if (freq[a[i] + 500] == 2) {
            int is_first_occurrence = 1;
            for (j = 0; j < i; j++) {
                if (a[j] == a[i]) {
                    is_first_occurrence = 0;
                    break;
                }
            }
            
            if (is_first_occurrence) {
                found[found_count++] = a[i];
            }
        }
    }
    

    if (found_count == 0) {
        printf("none\n");
    } else {
        for (i = 0; i < found_count; i++) {
            if (i > 0) printf(" ");
            printf("%d", found[i]);
        }
        printf("\n");
    }
    
    return 0;
}