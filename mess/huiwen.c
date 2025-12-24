#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


//法一
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char s[100];
        scanf("%s", s);

        int len = strlen(s);
        int sum = 0;

        for (int j = len - 1; j >= 0; j--) {
            int digit = s[j] - '0';
            sum += digit * pow(10, j);
        }

        if (sum == atoi(s)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}


//法二
#include <stdio.h>

int main() {
    
}