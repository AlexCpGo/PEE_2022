#ifndef _SQSTACK_H_
#define _SQSTACK_H_

#define MaxSize 50
#define Elemtype int

/* SqStack Definition */
typedef struct{
	Elemtype data[MaxSize];
	int top;
}SqStack;

/* SqStack Operation Function */
void InitStack(SqStack S){
	S.top = -1;
}

bool StackEmpty(SqStack S){
	if(S.top==-1) return true; 
	else return false;
}

bool Push(SqStack &S, ElemType x){
	if(S.top==MaxSize-1) return false; //overflow
	S.data[++S.top] = x;
	return true;
}

bool Pop(SqStack &S, ElemType &x){
	if(S.top==-1) return false; //underflow
	x=S.data[S.top--];
	return true;
}

bool GetTop(SqStack S, ElemType &x){
	if(S.top==-1) return false; //underflow
	X=S.data[S.top];
	return true;
}

#endif
 
