#ifndef _SQLIST_H_
#define _SQLIST_H_

/*Initialized definition */
#define MaxSize 20
#define ElemType int

/* Static allocation sequence list */
typedef struct Sqlist{
	ElemType data[MaxSize];
	int length;
}sqlist;

/* Dynamic allocation Sequence list */
/* #define InitSize 10
 * typedef struct {
 *		ElemType *data;
 *		int MaxSize, length;
 *		} Sqlist;
 *
 * L.data = new ElemType[InitSize] or L.data = (ElemType*)malloc(sizeof(ElemType)*InitSize);
 */

#endif
