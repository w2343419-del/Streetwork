#include <stdio.h>
int main() {
    int arr[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    arr[4] = 6;
    int i = 0;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (i = 0; i < sz; i++) {
        printf("%d\n", arr[i]);
    }
    return 0;
}