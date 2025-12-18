#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a < 0) {
        a = -a;
    }

    if (b < 0) {
        b = -b;
    }

    if (c < 0) {
        c = -c;
    }

    if (d < 0) {
        d = -d;
    }

    int res = 0;
    res = a + b + c + d;

    printf ("%d", res);
    return 0;
}
