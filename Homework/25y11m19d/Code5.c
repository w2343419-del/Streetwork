/**
 * @brief 统计出现2次的数字
 * 
 * 算法思路：
 * 1. 使用频率数组统计每个数字的出现次数
 * 2. 再次遍历原数组，记录首次出现且频率为2的数
 * 3. 使用found数组避免重复输出
 * \n * 优化点：
 * - 两次遍历：第一次计数，第二次输出（保持顺序）
 * - 避免重复输出已处理的数\n * 时间复杂度：O(n)
 * 空间复杂度：O(n + 数值范围)
 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int a[20];
    int freq[1020] = {0};  // 频率数组，处理负数用偏移
    
    // 读取数据并计数
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        freq[a[i] + 500]++;
    }
    
    int found_count = 0;
    int found[20] = {0};
    
    // 找出所有出现2次的数，保持首次出现顺序
    for (int i = 0; i < n; i++) {
        // 检查a[i]是否已经被记录过
        int already_found = 0;
        for (int j = 0; j < found_count; j++) {
            if (found[j] == a[i]) {
                already_found = 1;
                break;
            }
        }
        
        // 如果出现2次且未被记录，则输出
        if (!already_found && freq[a[i] + 500] == 2) {
            if (found_count > 0) {
                printf(" ");
            }
            printf("%d", a[i]);
            found[found_count++] = a[i];
        }
    }
    
    // 如果没有找到则输出none
    if (found_count == 0) {
        printf("none");
    }
    
    printf("\n");
    
    return 0;
}
