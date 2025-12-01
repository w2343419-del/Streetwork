#include <stdio.h>
#include <string.h>

int main() {
    char a[99999];
    int n;
    scanf("%s", a);
    scanf("%d", &n);
    getchar();
    
    int len = strlen(a);

    for (int i = 0; i < n; i++) {
        if (n <= len){
            printf("%c", a[i]);
        } else {
            printf ("%s", a);
        }
    }
    
    return 0;
}
