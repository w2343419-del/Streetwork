/**
 * @brief 计算某日是全年第几天
 * 
 * 问题描述：
 * 输入年月日，计算这一天是这一年的第几天
 * 
 * 算法分析：
 * - 方法：累加前面月份的天数，再加上当月天数
 * - 关键：判断闰年，2月天数不同
 * - 闰年判断：(year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)
 * - 时间复杂度：O(1)，使用查表法
 * - 空间复杂度：O(1)
 * 
 * 优化：
 * - 使用数组存储每月天数更简洁
 * - 使用循环累加替代switch更灵活
 */
#include <stdio.h>

int main() {
    int n, year, month, day;  // n为测试用例数，year/month/day为日期
    scanf("%d", &n);
    
    // 每月天数（平年）
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &year, &month, &day);
        
        // 判断是否为闰年
        int is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        
        // 计算天数：累加前面月份的天数
        int day_of_year = day;
        for (int m = 1; m < month; m++) {
            day_of_year += days_in_month[m];
            // 如果是闰年且已经过了2月，需要加1天
            if (is_leap && m == 2) {
                day_of_year++;
            }
        }
        
        printf("%d\n", day_of_year);
    }
    
    return 0;
}