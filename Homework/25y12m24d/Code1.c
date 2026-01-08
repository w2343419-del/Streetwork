/**
 * @brief 升序链表构建与第m个节点查询
 * 
 * 问题描述：
 * 输入n个整数(0<n<100)，按升序构建单链表，输出第m个节点的数据值(1≤m≤n)
 * 
 * 算法分析：
 * - 插入排序法构建链表：读取一个数即按序插入，保持链表有序
 * - 查询：顺序遍历到第m个节点输出其data
 * - 清理：遍历释放全部节点
 * 
 * 时间复杂度：O(n²) - 每次插入最坏O(n)，共n次
 * 空间复杂度：O(n)
 * 
 * 优化点：
 * - 插入时使用前驱指针，简化指针操作
 * - 边建边插，避免额外排序
 */
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

/**
 * @brief 有序链表构造与查询
 * 
 * 算法思路：
 * 1. 边读取边插入，保持链表有序
 * 2. 插入时找到合适位置（二分查找位置）
 * 3. 查询第m个节点
 * 4. 释放内存
 * 
 * 时间复杂度：O(n²) - 每次插入O(n)
 * 空间复杂度：O(n)
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *pNext;
} NODE, *pNODE;

/**
 * @brief 向有序链表插入新节点
 * @param pHead 链表头指针
 * @param data 要插入的数据
 * @return 新的链表头指针
 */
pNODE insertSorted(pNODE pHead, int data) {
    // 创建新节点
    pNODE pNew = (pNODE)malloc(sizeof(NODE));
    pNew->data = data;
    pNew->pNext = NULL;
    
    // 空链表或插入到头部
    if (pHead == NULL || pHead->data > data) {
        pNew->pNext = pHead;
        return pNew;
    }
    
    // 查找插入位置
    pNODE pCurrent = pHead;
    while (pCurrent->pNext != NULL && pCurrent->pNext->data < data) {
        pCurrent = pCurrent->pNext;
    }
    
    // 插入节点
    pNew->pNext = pCurrent->pNext;
    pCurrent->pNext = pNew;
    
    return pHead;
}

int main() {
    int n;
    scanf("%d", &n);

    pNODE pHead = NULL;

    // 读取n个数并插入有序链表
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        pHead = insertSorted(pHead, num);
    }

    int m;
    scanf("%d", &m);

    // 查找第m个节点
    pNODE pCurrent = pHead;
    for (int i = 1; i < m && pCurrent != NULL; i++) {
        pCurrent = pCurrent->pNext;
    }
    
    if (pCurrent != NULL) {
        printf("%d\n", pCurrent->data);
    }

    // 释放链表内存
    pCurrent = pHead;
    while (pCurrent != NULL) {
        pNODE pTemp = pCurrent;
        pCurrent = pCurrent->pNext;
        free(pTemp);
    }

    return 0;
}
