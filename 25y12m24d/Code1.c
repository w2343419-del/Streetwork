/*有如下的结构体：
typedef struct Node  
{  
    int data;//存放数据
    struct Node *pNext;//指向下一个结构体对象
}NODE,*pNODE;
现输入n（0<n<100）个数字，请用这n个整数构造出一个升序的链表，并打印出给定位置m（0<m<=n）的值；

输入
n
N1 N2 N3 ... Nn
m

输出
链表中第m个位置的data值

样例
输入
2
1 2
1
输出
1

输入
4
7 5 0 2
3
输出
5*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pNext;
} NODE, *pNODE;

pNODE insertSorted(pNODE pHead, int data) {
    pNODE pNew = (pNODE)malloc(sizeof(NODE));
    pNew->data = data;
    pNew->pNext = NULL;
    
    if (pHead == NULL || pHead->data > data) {
        pNew->pNext = pHead;
        return pNew;
    }
    
    pNODE pCurrent = pHead;
    while (pCurrent->pNext != NULL && pCurrent->pNext->data < data) {
        pCurrent = pCurrent->pNext;
    }
    
    pNew->pNext = pCurrent->pNext;
    pCurrent->pNext = pNew;
    
    return pHead;
}

int main() {
    int n;
    scanf("%d", &n);

    pNODE pHead = NULL;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        pHead = insertSorted(pHead, num);
    }

    int m;
    scanf("%d", &m);

    pNODE pCurrent = pHead;
    for (int i = 1; i < m && pCurrent != NULL; i++) {
        pCurrent = pCurrent->pNext;
    }
    
    if (pCurrent != NULL) {
        printf("%d\n", pCurrent->data);
    }

    pCurrent = pHead;
    while (pCurrent != NULL) {
        pNODE pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pTemp);
    }

    return 0;
}
