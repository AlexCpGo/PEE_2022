#ifndef _LINKQUEUE_H_
#define _LINKQUEUE_H_

#define MaxSize 50
#define Elemtype int
#define NULL -1;

/* SqQueue Definition */
typedef struct{
	Elemtype data;
	Struct QNode *next;
}QNode, *Queueptr;

typedef struct{
	QNode *front, *rear;
}LinkQueue;

/* LinkQueue Operation Function */
void InitQueue(LinkQueue &Q){
	Q.front = Q.rear = (QNode*)malloc(sizeof(QNode));
	Q.front->next = NULL;
}

bool QueueEmpty(LinkQueue &Q){
	if(Q.rear==Q.front) return true;
	else return false;
}

void EnQueue(SqQueue &Q, ElemTpye x){
	QNode *s = (QNode*)malloc(sizeof(QNode));	
	s->data = x;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
}

bool DeQueue(SqQueue &Q, ElemTpye &x){
	if(Q.rear==Q.front) return false;
	QNode *p = Q.front->next;
	x = p->data;
	Q.front->next = p->next;
	if(Q.rear==p) Q.rear = Q.front;
	free(p);
	return true;
}

bool GetHead(SqQueue Q, ElemTpye&x){
	if(Q.rear==Q.front) return false;
	QNode *p = Q.front->next;
	x = p->data;
	return true;
}
#endif
 
