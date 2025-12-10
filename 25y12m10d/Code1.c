/*你是一名赛博都市的“灯光调校师”。
城市里最火的一条霓虹跑道由 m × n 块灯砖铺成，每块灯砖亮度为 0 − 9 的数字。
今晚的演出特效只有一个：把所有灯砖整体向右循环移动 k 格，就像一条无限卷轴的霓虹长龙。
演出倒计时开始，你必须在灯光亮起前把最终图案算出来。

输入
第一行：三个整数 m 、n 、k，同空格分隔。（1≤m,n≤20，0≤k≤10^5）
接下来 m 行，每行 n 个字符 （0−9），表示初始灯砖亮度。

输出
共 m 行，每行 n 个字符，中间无空格，为右移后的跑道图案。

样例

输入1
2 4 1
2024
1234

输出1
4202
4123*/

#include <stdio.h>

int main() {
    int m, n, k;
    scanf("%d %d %d", &m, &n, &k);
    
    while (getchar() != '\n');
    
    char arr[m][n];
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = getchar();
        }
        if (i < m - 1) {
            while (getchar() != '\n');
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", arr[i][(j - k %n + n) % n]);
        }
        printf("\n");
    }

    return 0;
}
