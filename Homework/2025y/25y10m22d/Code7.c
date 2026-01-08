/**
 * @brief 判断是否为闰年
 * 
 * 闰年规则（格里高利历）：
 * 1. 能被400整除 → 是闰年
 * 2. 能被100整除但不能被400整除 → 不是闰年
 * 3. 能被4整除但不能被100整除 → 是闰年
 * 4. 其他年份 → 不是闰年
 * 
 * 时间复杂度：O(n)
 * 空间复杂度：O(1)
 */

#include <stdio.h>

int is_leap_year(int year) {
    return (year > 0) && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0));
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int year;
        scanf("%d", &year);
        
        // 判断是否为闰年：能被400整除或(能被4整除且不能被100整除)
        if (is_leap_year(year)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    
    return 0;
}
