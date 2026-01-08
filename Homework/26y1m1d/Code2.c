#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    int new_1, new_2, new_3;
    new_1 = pow(a, 3);
    new_2 = pow(b, 3);
    new_3 = pow(c, 3);

    int sum = 0;
    sum = new_1 + new_2 + new_3;
    printf("%d", sum);
    return 0;
}