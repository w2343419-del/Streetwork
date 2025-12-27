/*已知有结构体如下：
typedef struct _student {
    char name[10];
    char stuNum[20];
    struct _student *nextStu;
} StudentType;

请输入若干学生信息（即姓名和学号），并将学号相同的学生删除，仅保留第一个该学号的学生。

输入
一个正整数n表示将要输入的学生信息。随后输入n个学生的姓名与学号。

输出
按输入顺序依次输出学生的信息，每个学生信息占一行，且姓名和学号用一个空格隔开。

样例
输入	
4
zhangsan 2017141461001
lisi 2017141461002
wangwu 2017141461003	
yanliu 2017141461003	

输出 
zhangsan 2017141461001	
lisi 2017141461002	
wangwu 2017141461003*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _student {
    char name[10];
    char stuNum[20];
    struct _student *nextStu;
} StudentType;

int main() {
    int n;
    scanf("%d", &n);
    
    StudentType *head = NULL;
    StudentType *current = NULL;
    
    for (int i = 0; i < n; i++) {
        StudentType *newStudent = (StudentType *)malloc(sizeof(StudentType));
        scanf("%s %s", newStudent->name, newStudent->stuNum);
        newStudent->nextStu = NULL;
        
        if (head == NULL) {
            head = newStudent;
            current = newStudent;
        } else {
            current->nextStu = newStudent;
            current = newStudent;
        }
    }
    
    StudentType *prev = NULL;
    StudentType *currentNode = head;
    
    while (currentNode != NULL) {
        StudentType *tempNode = head;
        int foundDuplicate = 0;
        
        while (tempNode != currentNode) {
            if (strcmp(tempNode->stuNum, currentNode->stuNum) == 0) {
                foundDuplicate = 1;
                break;
            }
            tempNode = tempNode->nextStu;
        }
        
        if (!foundDuplicate) {
            prev = currentNode;
            currentNode = currentNode->nextStu;
        } else {
            StudentType *toDelete = currentNode;
            if (prev == NULL) {
                head = currentNode->nextStu;
                currentNode = head;
            } else {
                prev->nextStu = currentNode->nextStu;
                currentNode = currentNode->nextStu;
            }
            free(toDelete);
        }
    }
    
    StudentType *printNode = head;
    while (printNode != NULL) {
        printf("%s %s\n", printNode->name, printNode->stuNum);
        printNode = printNode->nextStu;
    }
    
    return 0;
}
