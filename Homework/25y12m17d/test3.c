#include <stdio.h>

int main() {
    long long int n;
    double s = 0.0;
    scanf("%lld", &n);
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            s += 1.0 / i;
        } else {
            s -= 1.0 / i;
        }
    }
    
    printf("%.4f", s);
    return 0;
}