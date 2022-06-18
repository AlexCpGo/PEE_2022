#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include <stdlib.h>
#include <stdio.h>

#define ElemType int
#define EndIn 999
#define NULL 0
//#define NULL -1

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;


LinkList List_TailInsert(LinkList &L){
	//printf("\n-------------LinkList Initilizing......-------------\n");
	int x;
	L=(LinkList)malloc(sizeof(LNode));
	LNode *s, *r=L;
	printf("Enter the numbers you want to insert into the empty LinkList:\n");
	scanf("%d", &x);
	
	
	//Input 999 for end
	printf("\nInitially, ");
	printf("LinkList is:\n");
	while(x!=EndIn){
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x;
		printf("%d ",s->data);
		r->next = s;
		r = s;
		scanf("%d", &x);
	}
	r->next = NULL;
	printf("\n-------------LinkList Initialized!-------------\n\n");
	return L;
}

int GetLinkListLength(LinkList L){
	int length = 0;
	LNode *s = L;
	while(s!=NULL){
		length++;
		s = s->next;
	}
	//printf("Length of the LinkList l is %d: \n", length);
	return length;
}

#endif

