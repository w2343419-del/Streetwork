/**
 * @brief 统计出现次数为2的数字
 * 
 * 问题描述：
 * 找出数组中所有恰好出现两次的数字
 * 
 * 算法分析：
 * - 统计每个数字的出现次数
 * - 找出计数为2的数字
 * - 按首次出现顺序输出，避免重复
 * - 时间复杂度：O(n²)
 * - 空间复杂度：O(n)
 * 
 * 优化点：
 * 可使用哈希表优化到O(n)时间
 */

#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	
	int a[20];
	int count[20] = {0};
	
	// 读取n个整数
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	
	// 统计每个数字的出现次数
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] == a[j]) {
				count[i]++;
			}
		}
	}
	
	// 找出恰好出现2次的数字，按首次出现顺序输出
	int found = 0;
	for (int i = 0; i < n; i++) {
		if (count[i] == 2) {
			// 检查是否已经输出过该数字
			int printed = 0;
			for (int j = 0; j < i; j++) {
				if (a[i] == a[j] && count[j] == 2) {
					printed = 1;
					break;
				}
			}
			
			if (!printed) {
				if (found) printf(" ");
				printf("%d", a[i]);
				found = 1;
			}
		}
	}
	
	// 如果没有找到任何出现2次的数字，输出none
	if (!found) {
		printf("none");
	}
	printf("\n");
	
	return 0;
}
