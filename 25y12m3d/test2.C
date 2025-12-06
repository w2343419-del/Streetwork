#include <stdio.h>

void cal(int *sum, int *seq, int *x, int *y) {
    *sum = *x + *y;
    *seq = *x - *y;
}

int main() {
    int x, y;
    int sum = 0, seq = 0;
    
    scanf("%d %d", &x, &y);
    
    cal(&sum, &seq, &x, &y);
    
    printf("%d\n", sum);
    printf("%d\n", seq);
    
    return 0;
}