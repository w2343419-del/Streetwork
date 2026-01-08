#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct WordNode 
{
	char str[64];    //字符串
	int count;    //出现次数
	struct WordNode *pnext;    //指向下一个节点的指针 
} WordNode;

void PrintList(WordNode *phead)
{
	WordNode *p = phead;

	printf("-----head===>addr=%p-------\n", p);
	while (p != NULL) {
		printf("%s, %d, adr=0x%x===>nextadr=0x%x\n", p->str, p->count, p, p->pnext);
		p = p->pnext;
	} 
	printf("---------------------------\n");
} 

WordNode * InsertNode(WordNode *phead, char *s)
{
	WordNode *pnew = (WordNode *)malloc(sizeof(WordNode));
	if (pnew == NULL) {
		return phead;
	}
	strcpy(pnew->str, s);
	pnew->count = 1;
	pnew->pnext = phead;
	return pnew;
}

int main()
{
	int i;
	char s[64];
	WordNode * phead = NULL;
	
	for (i = 0; i < 3; i++)
	{
		scanf("%s", s);
		phead = InsertNode(phead, s);
	}
	
	PrintList(phead);
	
	return 0;
}
