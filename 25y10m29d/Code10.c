/*描述

 

输入某年某月某日，判断这一天是这一年的第几天？

 

输入

 

第1行是一个整数n，表示随后有n组数据。每组数据占一行，包含3个整数year，month和day，以空格隔开。

 

输出

 

对每组数据输出这一天是这一年的第几天，并换行。

 

样例

 

输入

输出

3

2016 1 1

2016 3 1

2015 12 12

1

61

346*/
#include <stdio.h>
int main(){
    int n, year, mouth, day;
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ ) {
        scanf("%d %d %d", &year, &mouth, &day);
        
        year > 0;
        mouth > 0;
        day > 0;
        
        if ((year % 4 == 0 && year %100 != 0) || (year % 400 == 0)) {
            switch ( mouth ) {
                case 1:  day = day;        break;
                case 2:  day += 31;   break;
                case 3:  day += 60;   break;
                case 4:  day += 91;   break;
                case 5:  day += 121;  break;
                case 6:  day += 152;  break;
                case 7:  day += 182;  break;
                case 8:  day += 213;  break;
                case 9:  day += 244;  break;
                case 10: day += 274;  break;
                case 11: day += 305;  break;
                case 12: day += 335;  break;
            }
        } else {
            switch ( mouth ) {
                case 1:  day = day;        break;
                case 2:  day += 31;   break;
                case 3:  day += 59;   break;
                case 4:  day += 90;   break;
                case 5:  day += 120;  break;
                case 6:  day += 151;  break;
                case 7:  day += 181;  break;
                case 8:  day += 212;  break;
                case 9:  day += 243;  break;
                case 10: day += 273;  break;
                case 11: day += 304;  break;
                case 12: day += 334;  break;
            }

        }
    printf("%d\n", day);
    }
    return 0;
}