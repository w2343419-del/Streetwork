/*读入n名学生的姓名、身份证号、成绩。
查找并输出匹配查找串的学生的姓名和学号和成绩。
学生名单中可能缺考，没有成绩，表示为n/a。
如果查找串是针对姓名或者身份证号，则是模糊查找，即只要其中包含查找串(区分大小写)即算满足条件，
如果查找串是针对成绩，则是精确查找。

输入
每个测试输入包含1个测试用例，格式为
第1行：正整数n  待查找串
第2行：第1个学生的姓名 学号 成绩
第3行：第2个学生的姓名 学号 成绩
... ... ...
第n+1行：第n个学生的姓名 学号 成绩
其中姓名为不超过10个字符的字符串，身份证是标准18位，成绩为0到100之间的一个整数。

输出
输出包含相应查找串的学生信息（姓名 学号 成绩），每个学生一行。

样例1
输入
3 Joe
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 n/a
输出
Joe 510502199001011234 89

样例2
输入
3 199
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 n/a
输出
Joe 510502199001011234 89
Mary 510502199901011235 n/a

样例3
输入
3 n/a
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 n/a
输出
Mary 510502199901011235 n/a*/

#include <stdio.h>
#include <string.h>

struct student {
    char name[11];
    char id[20];
    char score[10];
};

typedef struct student stu;

int main() {
    int n;
    char target[20];
    scanf("%d %s", &n, target);

    for (int i = 0; i < n; i++) {
        stu x;
        scanf("%s %s %s", x.name, x.id, x.score);
        
        if (strstr(x.name, target) != NULL || strstr(x.id, target) != NULL || strcmp(x.score, target) == 0) {
            printf("%s %s %s\n", x.name, x.id, x.score);
        }
    }

    return 0;
}
    