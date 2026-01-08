/**
 * @brief 计算整数二进制表示中1的个数
 * 
 * 问题描述：
 * 统计一个正整数在二进制表示中有多少个1
 * 
 * 算法分析：
 * - 方法：位运算 + 循环检测
 * - 每次检查最低位是否为1（num % 2 或 num & 1）
 * - 右移一位继续检查（num >> 1）
 * - 时间复杂度：O(log n)，n为数值大小
 * - 空间复杂度：O(1)
 * 
 * 优化点：
 * - 使用位运算右移，效率高于除法
 * - 也可使用Brian Kernighan算法：num & (num-1)消除最右侧的1
 */
#include <stdio.h>

int main() {
    int n;  // 测试用例数
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;  // 待检测的数
        scanf("%d", &num);
        
        int count = 0;  // 二进制中1的个数
        
        // 逐位检查二进制表示
        while (num > 0) {
            // 检查最低位是否为1
            if (num & 1) {  // 等价于 num % 2 == 1，但位运算更快
                count++;
            }
            num >>= 1;  // 右移一位，等价于 num / 2
        }
        
        printf("%d\n", count);
    }
    
    return 0;  
    
}