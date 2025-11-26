#include <stdio.h>
int m, n, 
p, q, min_step = 999999999;
int a [51][51];
int v [51][51];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

void dsf(int x, int y, int step) {
    if (x == p && y == q) {
        if (step < min_step) {
            min_step = step;
            return;
        }
    }

    for (int i = 0; i < 4; i++) {
        int tx, ty;
        tx = x + dx[i];
        ty = y + dy[i];
    
        if (tx >= 1 && tx <= m && ty >= 1 && ty <= n && a[tx][ty] == 1 && v[tx][ty] == 0) {
            v[tx][ty] = 1;
            dsf(tx, ty, step + 1);
            v[tx][ty] = 0;
        }
    }

}

int main() {
    int startx, starty;
    scanf("%d%d", &m, &n);

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    scanf("%d%d%d%d", &startx, &starty, &p, &q);
    v[startx][starty] = 1;
    dsf(startx, starty, 0);
    printf("%d\n", min_step);

    return 0;
}