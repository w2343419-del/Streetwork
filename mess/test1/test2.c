#include <stdio.h>
#include <stdlib.h>

int judge(const int a[], int n) {
    if (n == 1) {
        return a[0] != 0;
    }

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < 1) return 1;
        sum += a[i];
    }
    if (sum != 2LL * (n - 1)) {
        return 1;
    }

    int available = a[0];
    for (int i = 1; i < n; i++) {
        if (available <= 0) {
            return 1;
        }
        available--;
        available += a[i] - 1;
    }

    return 0;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) {
        return 0;
    }
    
    for (int i = 0; i < t; i++) {
        int n;
        if (scanf("%d", &n) != 1) {
            return 0;
        }

        int a[n]; 

        for (int k = 0; k < n; k++) {
            if (scanf("%d", &a[k]) != 1) {
                return 0;
            }
        }

        int count = judge(a, n);

        if (count == 1) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    
    return 0;
}