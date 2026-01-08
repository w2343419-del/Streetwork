/*众所周知，日期有两种表示方法:MM/DD/YY或者YY/MM/DD.我们假设本题讨论的年份的格式都是20YY。
给你一个字符串，如果它只能代表一个合法的日期，满足MM/DD/YY的格式或者是YY/MM/DD的格式，那么输出 “month date,year”的格式（见第二个样例），
否则输出在这两种表示法下的日期差（见第一个样例）。

提示1：一年有12个月，分别是January, February, March, April, May, June, July, August, September, October, November 和 December。
提示2：注意闰年2月份有29天。闰年需要满足以下两个条件之一:
年份是400的倍数。
年份是4的倍数但年份不是100的倍数。

输入
一个时间字符串，格式为AA/BB/CC。保证AA/BB/CC至少满足两种表示法其中之一。

输出
见描述。

样例

输入
02/07/19
19/02/07

输出
6047
February 7, 2019

提示
样例1：02/07/19可能是2019.2.7(采用MM/DD/YY表示法)或者是2002.7.19(采用YY/MM/DD表示法)。这两个日期相差6047天。
样例2：19/02/07只能是2019.2.7(YY/MM/DD表示法)。也就是只能代表这一个日期，按照要求输出即可。*/

#include <stdio.h>

int main() {
    char s[9];
    scanf("%s", s);

    int aa, bb, cc;
    sscanf(s, "%d/%d/%d", &aa, &bb, &cc);
    
    int valid1 = 0;
    int month1 = aa, day1 = bb, year1 = 2000 + cc;
    
    if (aa >= 1 && aa <= 12 && bb >= 1 && bb <= 31 && cc >= 0 && cc <= 99) {
        valid1 = 1;
    }
    
    int valid2 = 0;
    int year2 = 2000 + aa, month2 = bb, day2 = cc;
    
    if (aa >= 0 && aa <= 99 && bb >= 1 && bb <= 12 && cc >= 1 && cc <= 31) {
        valid2 = 1;
    }

    if (valid1 && !valid2) {
        switch (month1) {
            case 1:     printf("January %d, %d\n", day1, year1);     break;
            case 2:     printf("February %d, %d\n", day1, year1);    break;
            case 3:     printf("March %d, %d\n", day1, year1);       break;
            case 4:     printf("April %d, %d\n", day1, year1);       break;
            case 5:     printf("May %d, %d\n", day1, year1);         break;
            case 6:     printf("June %d, %d\n", day1, year1);        break;
            case 7:     printf("July %d, %d\n", day1, year1);        break;
            case 8:     printf("August %d, %d\n", day1, year1);      break;
            case 9:     printf("September %d, %d\n", day1, year1);   break;
            case 10:    printf("October %d, %d\n", day1, year1);     break;
            case 11:    printf("November %d, %d\n", day1, year1);    break;
            case 12:    printf("December %d, %d\n", day1, year1);    break;
        }
    } else if (!valid1 && valid2) {
        switch (month2) {
            case 1:     printf("January %d, %d\n", day2, year2);     break;
            case 2:     printf("February %d, %d\n", day2, year2);    break;
            case 3:     printf("March %d, %d\n", day2, year2);       break;
            case 4:     printf("April %d, %d\n", day2, year2);       break;
            case 5:     printf("May %d, %d\n", day2, year2);         break;
            case 6:     printf("June %d, %d\n", day2, year2);        break;
            case 7:     printf("July %d, %d\n", day2, year2);        break;
            case 8:     printf("August %d, %d\n", day2, year2);      break;
            case 9:     printf("September %d, %d\n", day2, year2);   break;
            case 10:    printf("October %d, %d\n", day2, year2);     break;
            case 11:    printf("November %d, %d\n", day2, year2);    break;
            case 12:    printf("December %d, %d\n", day2, year2);    break;
        }
    } else {
        int total1 = 0;
        
        for (int y = 2000; y < year1; y++) {
            if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
                total1 += 366;
            } else {
                total1 += 365;
            }
        }
        
        for (int m = 1; m < month1; m++) {
            int d = 0;
            
            switch (m) {
                case 1: 
                case 3: 
                case 5: 
                case 7: 
                case 8: 
                case 10: 
                case 12:    d = 31;    break;
                
                case 4: 
                case 6: 
                case 9: 
                case 11:    d = 30;    break;
                case 2:
                    if ((year1 % 400 == 0) || (year1 % 4 == 0 && year1 % 100 != 0)) {
                        d = 29;
                    } else {
                        d = 28;
                    }
                    break;
            }
            
            total1 += d;
        }
        
        total1 += day1;
        
        int total2 = 0;
        
        for (int y = 2000; y < year2; y++) {
            if ((y % 400 == 0) || (y % 4 == 0 && y % 100 != 0)) {
                total2 += 366;
            } else {
                total2 += 365;
            }
        }
        
        for (int m = 1; m < month2; m++) {
            int d = 0;
            
            switch (m) {
                case 1: 
                case 3: 
                case 5: 
                case 7: 
                case 8: 
                case 10: 
                case 12:    d = 31;    break;
                
                case 4: 
                case 6: 
                case 9: 
                case 11:    d = 30;    break;
                
                case 2:
                    if ((year2 % 400 == 0) || (year2 % 4 == 0 && year2 % 100 != 0)) {
                        d = 29;
                    } else {
                        d = 28;
                    }
                    break;
            }
            
            total2 += d;
        }
        
        total2 += day2;

        int diff;
        
        if (total1 > total2) {
            diff = total1 - total2;
        } else {
            diff = total2 - total1;
        }
       
        printf("%d\n", diff);
    }
    
    return 0;
}