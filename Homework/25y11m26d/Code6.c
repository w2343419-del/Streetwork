/*给一个 N×M 的字符矩阵 S，Si,j ∈{U,D,L,R}。
设当前位置为 (x,y)，定义一次移动为：
若 Sx,y=U，则向上移动到 (x−1,y)，若 x=1，则移动到 (N,y)。
若 Sx,y=D，则向下移动到 (x+1,y)，若 x=N，则移动到 (1,y)。
若 Sx,y=L，则向左移动到 (x,y−1)，若 y=1，则移动到 (x,M)。
若 Sx,y=R，则向右移动到 (x,y+1)，若 y=M，则移动到 (x,1)。
有 Q 次询问。
每次询问给出一个初始坐标 (x0,y0)，和移动次数 step，回答经过 step 次移动后到达的坐标。

限制
时间限制 1s，空间限制 256M
1≤N,M,Q≤50
Si,j∈{U,D,L,R}(1≤i≤N,1≤j≤M)
1≤x0≤N
1≤y0≤M
1≤step≤3000

输入
第一行输入 N,M。
接下来有N行，每行有 M 个字符，字符取值范围为 U,D,L,R。
接下来一行输入 Q。
接下来有 Q 行，每行输入 x0,y0,step。

输出
对于每个询问，输出答案，每行输出两个整数，表示坐标。

样例
输入
5 5
UDRRU
LRDDL
DLUUD
RULLR
UDURU
5
1 1 1
2 1 2
3 3 10
4 2 99
3 5 3000

输出
5 1
2 4
3 3
4 1
3 2

解释
对于第 1 次询问，(1,1) 向上移动一次到达 (5,1)
对于第 2 次询问，(2,1) 向左移动一次到达 (2,5)，向左移动一次到达 (2,4)
对于第 3 次询问，路径为 (3,3),(2,3),(3,3),(2,3),(3,3),(2,3),(3,3),(2,3),(3,3),(2,3),(3,3)*/
#include <stdio.h>
int main() {
    int n, m;
    char s[51][51]; 
    scanf("%d %d", &n, &m);

    int c;
    while (1) {
        c = getchar();
        if (c == EOF || c == '\n') {
            break;
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%c", &s[i][j]);
        }
        while (1) {
            c = getchar();
            if (c == EOF || c == '\n') {
                break;
            }
        }
    }

    int q;
    scanf("%d", &q);

    while (q--) {
        int x0, y0, step;
        scanf("%d %d %d", &x0, &y0, &step);
        int dx = x0, dy = y0;
        for (int i = 0; i < step; i++) {
            char d = s[dx - 1][dy - 1];            
            switch (d) {
                case 'U': {
                    if (dx == 1) {
                        dx = n;
                    } else {
                        dx = dx - 1;
                    }
                    break;
                }
                case 'D': {
                    if (dx == n) {
                        dx = 1;
                    } else {
                        dx = dx + 1;
                    }
                    break;
                }
                case 'L': {
                    if (dy == 1) {
                        dy = m;
                    } else {
                        dy = dy - 1;
                    }
                    break;
                }
                case 'R': {
                    if (dy == m) {
                        dy = 1;
                    } else {
                        dy = dy + 1;
                    }
                    break;
                }
            }
        }
        printf("%d %d\n", dx, dy);
    }
    return 0;
}