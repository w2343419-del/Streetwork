/*读入n名学生的姓名、身份证号、成绩。
查找并输出匹配查找串的学生的姓名和学号和成绩。
学生名单中可能缺考，没有成绩，表示为n/a。
如果查找串是针对姓名或者身份证号，则是模糊查找，即只要其中包含查找串(区分大小写)即算满足条件，如果查找串是针对成绩，则是精确查找。

输入
每个测试输入包含1个测试用例，格式为
正整数n 待查找串
第1个学生的姓名 学号 成绩
第2个学生的姓名 学号 成绩
… … …
第n个学生的姓名 学号 成绩
其中n≤10，姓名为不超过10个字符的字符串，身份证是标准18位，成绩为0到100之间的一个整数。

输出
输出包含相应查找串的学生信息(姓名 学号 成绩 排名)(如果成绩为n/a，则排名就为n/a)，项之间用空格隔开。
每个学生一行。
其中排名是按照成绩降序排列的排名。
如果有多个学生的成绩相同，则这些学生的排名相同，并且随后的几个排名将跳过。
满足条件的多个学生按照输入的顺序输出。

样例1
输入
3 Joe
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 n/a
输出
Joe 510502199001011234 89 2

样例2
输入
3 1234
Joe 510502199001011234 89
Mike 51050220000101123x 100
Mary 510502199901011235 90
输出
Joe 510502199001011234 89 3*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student {
    char name[11];
    char id[20];
    char score_str[10];
    int score_val;
    int rank;
    int input_order;
};

typedef struct student stu;

int cmp_score(const void *a, const void *b) {
    stu *s1 = (stu *)a;
    stu *s2 = (stu *)b;
    
    return s2->score_val - s1->score_val;
}

int cmp_order(const void *a, const void *b) {
    stu *s1 = (stu *)a;
    stu *s2 = (stu *)b;
    
    return s1->input_order - s2->input_order;
}

int main() {
    int n;
    char target[20];
    
    if (scanf("%d %s", &n, target) != 2)    return 0;

    stu students[11];

    for (int i = 0; i < n; i++) {
        scanf("%s %s %s", students[i].name, students[i].id, students[i].score_str);
        
        students[i].input_order = i;
        
        if (strcmp(students[i].score_str, "n/a") == 0) {
            students[i].score_val = -1;
        } else {
            students[i].score_val = atoi(students[i].score_str);
        }
    }

    qsort(students, n, sizeof(stu), cmp_score);

    for (int i = 0; i < n; i++) {
        if (students[i].score_val == -1) {
            students[i].rank = -1;
        } else {
            if (i > 0 && students[i].score_val == students[i-1].score_val) {
                students[i].rank = students[i-1].rank;
            } else {
                students[i].rank = i + 1;
            }
        }
    }

    qsort(students, n, sizeof(stu), cmp_order);

    for (int i = 0; i < n; i++) {
        int match = 0;
        
        if (strstr(students[i].name, target) != NULL || strstr(students[i].id, target) != NULL) {
            match = 1;
        }
        
        if (strcmp(students[i].score_str, target) == 0) {
            match = 1;
        }

        if (match) {
            printf("%s %s %s ", students[i].name, students[i].id, students[i].score_str);
            
            if (students[i].rank == -1) {
                printf("n/a\n");
            } else {
                printf("%d\n", students[i].rank);
            }
        }
    }

    return 0;
}
