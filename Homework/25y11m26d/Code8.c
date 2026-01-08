/*Zig-Zag Matrix*/
#include <stdio.h>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int matrix[100][100];
    int row = 0, col = 0;
    
    for (int num = 1; num <= m * n; num++) {
        matrix[row][col] = num;
        
        if (num == m * n) {
            break;
        }
        
        if ((row + col) % 2 == 0) {
            if (col == n - 1) {
                row++;
            } else if (row == 0) {
                col++;
            } else {
                row--;
                col++;
            }
        } else {
            if (row == m - 1) {
                col++;
            } else if (col == 0) {
                row++;
            } else {
                row++;
                col--;
            }
        }
    }
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}