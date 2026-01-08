/**
 * @brief 代码优化 - 算法改进与性能提升
 *
 * 算法思路：详见代码注释
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 *
 * 优化点：添加详细注释、改进算法效率
 */

#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	
	int a, b, c;
	int sum;
	
	// 提取个位数
	c = n % 10;
	// 提取十位数
	b = ( (n - c) / 10 ) % 10;
	// 提取百位数
	a = n / 100;
	
	// 计算三位数字之和
	sum = a + b + c;
	printf("%d", sum);
	return 0;
}
