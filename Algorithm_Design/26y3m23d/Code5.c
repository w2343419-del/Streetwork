/*5: 汉诺塔问题
描述
汉诺塔是根据一个传说形成的数学问题：

有三根杆子 A,B,C。
A 杆上有 N ( N > 1 ) 个穿孔圆盘，盘的尺寸由下到上依次变小。
要求按下列规则将所有圆盘移至 C 杆：

每次只能移动一个圆盘。
大盘不能叠在小盘上面。
现在将盘子从上到下依次编号为 1 ∼ N，请根据给出的 N 输出将所有圆盘移至 C 杆的步骤及总步数。

输入
多组数据，每组包含一行一个整数 N（1 ≤ N ≤ 10）。

输出
对于每组数据，第一行输出一个整数 k，表示移动的总步数。

接下来 k 行，每行以 step i: x From src To dst 的格式输出移动的每一步，
表示在第 i 步，将第 x 号盘子从 src 盘移动至 dst 盘。

样例

输入
1
2

输出
1
step 1: 1 From A To C
3
step 1: 1 From A To B
step 2: 2 From A To C
step 3: 1 From B To C*/

#include <stdio.h>

int N;

void move (int n, char src, char dst, char aux, int *step) {
    if (n == 1) {
        printf("step %d: 1 From %c To %c\n", (*step)++, src, dst);
    } else {
        move(n - 1, src, aux, dst, step);
        printf("step %d: %d From %c To %c\n", (*step)++, n, src, dst);
        move(n - 1, aux, dst, src, step);
    }
}

int main() {
    while (scanf("%d", &N) != EOF) {
        int step = 1;
        int total_steps = (1 << N) - 1;
        printf("%d\n", total_steps);
        move(N, 'A', 'C', 'B', &step);
    }
    return 0;
}