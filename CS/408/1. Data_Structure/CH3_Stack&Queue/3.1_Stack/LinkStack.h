#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_

typedef struct Linknode{
	ElemType data;
	struct Linknode *next;
}*LiStack;

#endif

