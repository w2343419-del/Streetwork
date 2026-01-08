/**
 * @brief 矩阵中的特殊元素查找
 * 
 * 问题描述：
 * 找出矩阵中满足条件的“精灵王”：
 * 元素值 = 上下左右四个邻居之和
 * 
 * 算法分析：
 * 1. 遍历矩阵每个元素
 * 2. 计算四个邻居的和（边界外计为0）
 * 3. 如果相等则记录坐标和值
 * 4. 按值降序排序，相同值按行列序排序
 * - 时间复杂度：O(m×n + k log k)
 * - 空间复杂度：O(m×n)
 * 
 * 实现要点：
 * 注意边界处理和排序规则
 */

/*在遥远的“矩阵大陆”，住着一群古怪的数字精灵。它们排成整齐的 m 行 n 列方阵，每个精灵都有独一无二的能量值。
有一天，精灵们突然意识到：
如果谁的能量值恰好等于“上下左右”四位邻居的能量之和（如果某位邻居不存在那么能量计为 0 ），就能觉醒成传说中的——精灵王！
觉醒的精灵王一起举行精灵议会，需要按照能量值安排位置。
请找出所有精灵王，并给他们安排座次。
如果大陆上没有精灵王觉醒，就直接输出 sleep，让大家继续沉睡吧！

输入
第一行：两个整数 m 、n，（1≤m,n≤15）
接下来 m 行：每行 n 个整数， −100 ≤ 整数 ≤ 100 ，中间用空格分隔。

输出
按从大到小的顺序输出精灵王的坐标，每个坐标占一行。如果两个精灵王能量值相等，则按行优先的顺序排列。如果没有则输出 sleep

样例
输入1
5 5
1 1 1 1 1
1 4 1 1 1
1 1 1 2 1
1 1 2 8 3
1 1 1 1 1

输出1
3 3
1 1

输入2
5 5
1 1 1 1 1
1 1 1 1 1
1 1 1 2 1
1 1 2 2 3
1 1 1 1 1

输出2
sleep

输入3
5 5
1 1 1 1 1
1 4 1 1 1
1 1 1 1 1
1 1 1 4 1
1 1 1 1 1

输出3
1 1
3 3*/
#include <stdio.h>
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int kings[230][10];
    int king_count = 0;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            
            if (i > 0) sum += matrix[i-1][j];
            if (i < m-1) sum += matrix[i+1][j];
            if (j > 0) sum += matrix[i][j-1];
            if (j < n-1) sum += matrix[i][j+1];
            
            if (matrix[i][j] == sum) {
                kings[king_count][0] = i;
                kings[king_count][1] = j;
                kings[king_count][2] = matrix[i][j];
                king_count++;
            }
        }
    }
    
    if (king_count == 0) {
        printf("sleep\n");
        return 0;
    }
    
    for (int i = 0; i < king_count-1; i++) {
        for (int j = 0; j < king_count-1-i; j++) {
            if (kings[j][2] < kings[j+1][2] || 
                (kings[j][2] == kings[j+1][2] && kings[j][0] > kings[j+1][0]) ||
                (kings[j][2] == kings[j+1][2] && kings[j][0] == kings[j+1][0] && kings[j][1] > kings[j+1][1])) {
                for (int k = 0; k < 3; k++) {
                    int temp = kings[j][k];
                    kings[j][k] = kings[j+1][k];
                    kings[j+1][k] = temp;
                }
            }
        }
    }
    
    for (int i = 0; i < king_count; i++) {
        printf("%d %d\n", kings[i][0], kings[i][1]);
    }
    
    return 0;
}