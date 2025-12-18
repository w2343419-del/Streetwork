/*读入n名学生的姓名、身份证号、成绩，分别输出成绩最高和成绩最低学生的姓名和身份证号。
注意：学生名单中可能缺考，没有成绩，表示为n/a.

输入
每个测试输入包含1个测试用例，格式为
正整数n
第1个学生的姓名 学号 成绩
第2个学生的姓名 学号 成绩
… … …
第n个学生的姓名 学号 成绩
其中1≤n≤100，姓名为不超过10个字符的字符串，身份证是标准18位，成绩为0到100之间的一个整数，字段之间用1个或多个空格隔开。
输入中至少有一位学生有成绩。

输出
对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，第2行是成绩最低学生的姓名和学号，项与项之间有1个空格。
如果成绩最高的学生有多个，输出姓名字典序最小的那个，如果成绩最低的有多个，输出姓名字典序最大的那个。

样例

输入
3
Joe   510502199001011234 89
Mike  51050220000101123x 100
Mary  510502199901011234 n/a

输出
Mike 51050220000101123x
Joe 510502199001011234*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name[12];
    char id[20];
    char score_str[10];
    int valid;
};

typedef struct student stu;

stu student[100];

int cmp(const void *a, const void *b) {
    stu *p1 = (stu *)a;
    stu *p2 = (stu *)b;

    if (p1->valid != p2->valid) {
        return p1->valid - p2->valid;
    }
    return strcmp(p2->name, p1->name);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int valid_count = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", student[i].name, student[i].id, student[i].score_str);
        if (strcmp(student[i].score_str, "n/a") == 0) {
            student[i].valid = -1;
        } else {
            student[i].valid = atoi(student[i].score_str);
        }
    }

    qsort(student, n, sizeof(stu), cmp);

    int first_valid = 0;
    while (first_valid < n && student[first_valid].valid == -1) {
        first_valid++;
    }

    printf("%s %s\n", student[n - 1].name, student[n - 1].id);
    printf("%s %s\n", student[first_valid].name, student[first_valid].id);

    return 0;
}
