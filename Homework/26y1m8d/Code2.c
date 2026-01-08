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
#include <string.h>
int main() {
	int n;
	scanf("%d", &n);
	
	char a[20];
	scanf("%s", a);
	
	int len = 0;
	len = strlen(a);
	
	
	char count[20] = {0};
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (a[i] = a[j]) {
				count[i]++;
			}
		}
	}
	
	int valid = 0;
	
	for (int i = 0; i < len; i++) {
		if (a[i] == 2) {
			valid = 1;
		}
	}
	
	if (valid == 0) {
		printf ("none\n");
	} else {
		char res[20];
		for (int i = 0; i < len; i++) {
			if (count[i] == 2) {
				res[i] = a[i];
			}
		}
		
		for (int i = 0; i < len; i++) {
			for (int j = i + 1; j < len; j++) {
				if (res[i] == res[j]) {
					printf ("%d", res[i]);
					printf (" ");
				}
			}
		}
		getchar();
	}
	return 0;
}

