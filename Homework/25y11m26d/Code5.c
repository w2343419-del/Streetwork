/**
 * @brief 约瑟夫环问题（Josephus Problem）
 * 
 * 问题：m个人围成一圈，从第1人开始数1,2,3...，报到3的人退出
 * 求最后剩下的人的初始位置\n * 算法思路：
 * 1. 使用数组表示m个人，初始值为1到m
 * 2. 从第0人开始，计数到第2个人（报到3）
 * 3. 删除该人，继续计数
 * 4. 重复直到只剩1人\n * 优化点：
 * - 使用取模运算避免重复遍历\n * 时间复杂度：O(m²)
 * 空间复杂度：O(m)
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d", &m);
        
        int p[m];
        // 初始化：p[i]表示第i个位置上的人的编号
        for (int j = 0; j < m; j++) {
            p[j] = j + 1;
        }
        
        int current = 0;  // 当前位置
        int remaining = m;  // 剩余人数
        
        while (remaining > 1) {
            // 报数2个位置（从current+1开始报1、2、3）
            // 所以第(current+2)%remaining个人出圈
            int out = (current + 2) % remaining;
            
            // 删除第out个人
            for (int j = out; j < remaining - 1; j++) {
                p[j] = p[j + 1];
            }
            
            remaining--;
            
            // 更新当前位置
            current = out % remaining;
        }
        
        printf("%d\n", p[0]);
    }
    
    return 0;
}
