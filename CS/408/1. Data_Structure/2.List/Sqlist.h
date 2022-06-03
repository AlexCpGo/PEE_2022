#ifndef _SQLIST_H_
#define _SQLIST_H_

/*Initialized definition */
#define MaxSize 8
#define ElemType int

/* Static allocation sequence list */
typedef struct Sqlist{
	ElemType data[MaxSize];
	int length;
}sqlist;

#endif
