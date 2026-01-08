//黑球3个，白球3个，蓝球6个，抓n个，有几种可能
#include <stdio.h>

int main() {
    int m;
    scanf("%d", &m);
    
    for (int t = 0; t < m; t++) {
        int n;
        scanf("%d", &n);
        
        int count = 0;
        int i, j, k;
        
        for (i = 0; i <= 3 && i <= n; i++) {      
            for (j = 0; j <= 3 && j <= n - i; j++) {    
                k = n - i - j;                          
                if (k >= 0 && k <= 6) {            
                    count++;
                }
            }
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}