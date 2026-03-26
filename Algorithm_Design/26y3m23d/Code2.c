/*2: 二叉树的最大深度
描述
二叉树是指每个结点最多有两个子树的树结构，这两个子树通常子树被称作“左子树”（left subtree）和“右子树”（right subtree）。
二叉树的结点层定义为：根结点的层定义为 1，根的孩子为第 2 层结点，依此类推；
二叉树的深度定义为：树中最大的结点层数。
给定一颗以 1 号结点为根的二叉树，求它的最大深度。

输入
每组数据包含一颗二叉树，以如下形式给出：
第一行为一个整数 n (1≤n≤20)，表示二叉树的结点个数，结点编号为 
1,2,⋯,n。
接下来直到输入数据末尾，每行为两个整数 
x,y，表示 x 和 y 之间有一条边，且 y 是 x 的儿子。
输入保证是一颗合法的二叉树。

输出
输出一行，表示给定的二叉树的最大深度。

样例
输入

3
1 2
2 3
输出

3*/

#include <stdio.h>

int children[25][2];
int child_count[25];

int max (int a, int b) {
    return a > b ? a : b;
}

int depth (int node) {
    if (child_count[node] == 0) {
        return 1;
    }
    if (child_count[node] == 1) {
        return 1 + depth(children[node][0]);
    }
    return 1 + max(depth(children[node][0]), depth(children[node][1]));
}


int main() {
    int n, x, y;
    scanf("%d", &n);

    while (scanf("%d %d", &x, &y) == 2) {
        children[x][child_count[x]++] = y;
    }

    printf("%d\n", depth(1));
    return 0;
}