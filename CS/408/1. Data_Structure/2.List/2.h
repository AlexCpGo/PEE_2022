#include <stdio.h>
#include "Sqlist.h"

/*------------------------Helper Function---------------------*/
int DeleteMin(Sqlist &L);
void ReverseSqlist(Sqlist &L);
void DeleteElem(Sqlist &L, int x);
bool DeleteOrdRange(Sqlist &L, int s, int t);
bool DeleteRange(Sqlist &L, int s, int t);

/* 
 * 2.1 DeleteMin
 *   DESCRIPTION: Delete the min element of the Sqlist and use the final idx element to replace its position
 *   INPUTS: Sqlist &L
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: Value of the deleted element
 *   SIDE EFFECTS: None
 */
int DeleteMin(Sqlist &L)
{
	int i;
	bool ERROR = 0;
	if (L.length == 0){
		printf("The Sequenlist is empty.\n");
		return ERROR;
	}
	
	int minValue = L.data[0];
	int minIdx = 0;
	for(i=0; i<L.length-1; ++i){
		if (L.data[i]<=minValue){
			minIdx = i;
		}
	}
	minValue = L.data[minIdx];
	L.data[minIdx] = L.data[L.length-1];
	L.length--; //length of the Sqlist decrease by 1;
			
	
	return minValue;
}

/* 
 * 2.2 ReverseSqlist
 *   DESCRIPTION: Reverse the Sqlist, S = O(1)
 *   INPUTS: Sqlist &L
 *   OUTPUTS: Reversed Sqlist &L
 *   RETURN VALUE: None
 *   SIDE EFFECTS: None
 */
void ReverseSqlist(Sqlist &L){
	int i, j, temp;
	for(i=0,j=L.length-1; i<j; ++i,--j){
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
	}
}

/* 
 * 2.3 DeleteElem
 *   DESCRIPTION: Delete element with value == x in the Sqlist L; 
 *				  Use a digit k to indicate the idx of the new Sqlist L,
 *                which is also equals to the number of elements not equal to x.
 *   INPUTS: Sqlist &L, int x
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: None
 *   SIDE EFFECTS: None
 */
void DeleteElem(Sqlist &L, int x){
	int i=0, k=0;
	for (i=0; i<=L.length-1; i++){
	// Only Retain the element not equals to x
	if(L.data[i]!=x){
		L.data[k] = L.data[i];
		k++;
	}	
	}
	L.length = k;
}

 /* 
 * 2.5 DeletOrdRange
 *   DESCRIPTION: Delete element in range[s,t] in the orderly Sqlist L; 
 *				  Use a i,j to indicate the element idx in range[s,t].
 *				  Move the elemtents behind j forward to the i
 *   INPUTS: Sqlist &L, int s, int t
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-succeess; 0-fali;
 *   SIDE EFFECTS: None
 */
bool DeleteOrdRange(Sqlist &L, int s, int t){
	int i, j;
	if (s>=t || L.length == 0){
		printf("\n\n--------------------ERROR!--------------------\n");
		return false;
	}

	for(i=0; i<L.length&&L.data[i]<s;i++);
	if(i>L.length){
		printf("\n\n--------------------ERROR!--------------------\n");
		return false;
	}

	for(j=i; j<L.length&&L.data[j]<=t; j++);
	for(; j<L.length; ++i,++j){
		L.data[i] = L.data[j];
	}
	L.length = i;
	return true;
}

 /* 
 * 2.5 DeleteRange
 *   DESCRIPTION: Delete element in range[s,t] in the Sqlist L; 
 *				  Use a digit k to indicate the idx of the new Sqlist L,
 *                which is also equals to the number of elements not equal to x.
 *   INPUTS: Sqlist &L, int s, int t
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-succeess; 0-fali;
 *   SIDE EFFECTS: None
 */
bool DeleteRange(Sqlist &L, int s, int t){
	int i=0, k=0;
	if (s>=t || L.length == 0){
		printf("\n\n--------------------ERROR!--------------------\n");
		return false;
	}
	for (i=0; i<=L.length-1; i++){
	// Only Retain the element not equals to x
		if(L.data[i]<s || L.data[i]>t){
			L.data[k] = L.data[i];
			k++;
		}	
	}
	L.length = k;
	return true;
}
