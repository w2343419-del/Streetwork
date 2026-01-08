#include <stdio.h>

int main() {
    int a[3][4] = {{1, 2, 3, 4}, 
                    {5, 6, 7, 8}, 
                    {9, 10, 11, 12}};
    
    int *p = (int *)a;
    
    p += 4;

    int sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += *(p + i);
    }

    printf("%d\n", sum);

    return 0;    
}
