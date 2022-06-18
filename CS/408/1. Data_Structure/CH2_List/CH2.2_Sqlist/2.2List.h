#ifndef _2_2_LIST_H_
#define _2_2_LIST_H_

#include <stdio.h>
#include "Sqlist.h"

/*------------------------Problem Variables---------------------*/

/*------------------------Problem Function---------------------*/
int DeleteMin(Sqlist &L);
void ReverseSqlist(Sqlist &L);
void DeleteElem(Sqlist &L, int x);
bool DeleteOrdRange(Sqlist &L, int s, int t);
bool DeleteRange(Sqlist &L, int s, int t);
bool DeleteRepeat(Sqlist &L);
bool MergeList(Sqlist &L1, Sqlist &L2);
bool ReorderList(Sqlist &L);
bool SearchElem(Sqlist &L, int x)

/* 
 * 2.2.1 DeleteMin
 *   DESCRIPTION: Delete the min element of the Sqlist and use the final idx element to replace its position
 *   INPUTS: Sqlist &L
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: Value of the deleted element
 *   SIDE EFFECTS: None
 */
int DeleteMin(Sqlist &L) {
	int i;
	bool ERROR = 0;
	if (L.length == 0){
		printf("The Sequenlist is empty.\n");
		return ERROR;
	}
	
	int minValue = L.data[0];
	int minIdx = 0;
	for (i=0; i<L.length-1; ++i){
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
 * 2.2.2 ReverseSqlist
 *   DESCRIPTION: Reverse the Sqlist, S = O(1)
 *   INPUTS: Sqlist &L
 *   OUTPUTS: Reversed Sqlist &L
 *   RETURN VALUE: None
 *   SIDE EFFECTS: None
 */
void ReverseSqlist(Sqlist &L) {
	int i, j, temp;
	for (i=0,j=L.length-1; i<j; ++i,--j) {
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
	}
}

/* 
 * 2.2.3 DeleteElem
 *   DESCRIPTION: Delete element with value == x in the Sqlist L; 
 *				  Use a digit k to indicate the idx of the new Sqlist L,
 *                which is also equals to the number of elements not equal to x.
 *   INPUTS: Sqlist &L, int x
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: None
 *   SIDE EFFECTS: None
 */
void DeleteElem(Sqlist &L, int x) {
	int i=0, k=0;
	for (i=0; i<=L.length-1; i++){
	// Only Retain the element not equals to x
	if (L.data[i]!=x){
		L.data[k] = L.data[i];
		k++;
	}	
	}
	L.length = k;
}

/* 
 * 2.2.4 DeletOrdRange
 *   DESCRIPTION: Delete element in range[s,t] in the orderly Sqlist L; 
 *				  Use a i,j to indicate the element idx in range[s,t].
 *				  Move the elemtents behind j forward to the i
 *   INPUTS: Sqlist &L, int s, int t
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-succeess; 0-fali;
 *   SIDE EFFECTS: None
 */
bool DeleteOrdRange(Sqlist &L, int s, int t) {
	int i, j;
	if (s>=t || L.length == 0){
		printf("\n\n--------------------ERROR!--------------------\n");
		return false;
	}

	for (i=0; i<L.length&&L.data[i]<s;i++);
	if (i>L.length){
		printf("\n\n--------------------ERROR!--------------------\n");
		return false;
	}

	for (j=i; j<L.length&&L.data[j]<=t; j++);
	for (; j<L.length; ++i,++j){
		L.data[i] = L.data[j];
	}
	L.length = i;
	return true;
}

/* 
 * 2.2.5 DeleteRange
 *   DESCRIPTION: Delete element in range[s,t] in the Sqlist L; 
 *				  Use a digit k to indicate the idx of the new Sqlist L,
 *                which is also equals to the number of elements not equal to x.
 *   INPUTS: Sqlist &L, int s, int t
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-succeess; 0-fali;
 *   SIDE EFFECTS: None
 */
bool DeleteRange(Sqlist &L, int s, int t) {
	int i=0, k=0;
	if (s>=t || L.length == 0){
		printf("\n\n--------------------ERROR!--------------------\n");
		return false;
	}
	for (i=0; i<=L.length-1; i++){
	// Only Retain the element not equals to x
		if (L.data[i]<s || L.data[i]>t){
			L.data[k] = L.data[i];
			k++;
		}	
	}
	L.length = k;
	return true;
}

/* 
 * 2.2.6 DeleteRepeat
 *   DESCRIPTION: Delete repeated elements and remain ones in a ordered Sqlist L
 *				  to make every element in the Sqlist L different
 *                Use L.data[i] to compare the elements behind it, 
 * 				  if repeated, delete the repeated ones after it
 *   INPUTS: Sqlist &L
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-succeess; 0-fali;
 *   SIDE EFFECTS: None
 */
bool DeleteRepeat(Sqlist &L) {
	if (L.length==0){
		return false;
	}
	int i,j;
	for (i=0,j=1; j<L.length; ++j){
		if (L.data[i]!=L.data[j]){
			L.data[++i]=L.data[j];
		}
	}
	L.length=i+1;
	return true;
}

/* 
 * 2.2.7 MergeList
 *   DESCRIPTION: Merge two ordered Sqlist into a new ordered Sqlist L
 *   INPUTS: Sqlist &L1, Sqlist &L2, empty Sqlist &L;
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-succeess; 0-fali;
 *   SIDE EFFECTS: None
 */

bool MergeList(Sqlist &L1, Sqlist &L2, Sqlist &L)
{
	int i=0, j=0, k=0;
	while (i<=L1.length-1 && j<=L2.length-1){
		if (L1.data[i]<=L2.data[j]){
			L.data[k++] = L1.data[i++]; 
		}
		else {L.data[k++] = L2.data[j++];} 
	}
	
	/* For two Sqlist lengths are different */
	while(i<=L1.length-1){L.data[k++] = L1.data[i++];}
	while(j<=L2.length-1){L.data[k++] = L2.data[j++];}
	//L.length = k;
	return true;
}

/* 
 * 2.2.8 ReorederList
 *   DESCRIPTION: Reorder the A[m+n] consisted of (a1, a2, a3...am) and (b1, b2, b3...bm)
 *					to make (b1, b2, b3...bm, a1, a2, a3...am)
 *   INPUTS: Sqlist &L
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-succeess; 0-fali;
 *   SIDE EFFECTS: None
 */
 
void Reverse(Sqlist &L, int left, int right){
	int temp, arraySize=L.length;
	if(left>=right || right>=arraySize) return;
	int mid =(left+right)/2;
	for (int i=0; i<mid-left; ++i){
		temp = L.data[left+i];
		L.data[left+i] = L.data[right-i];
		L.data[right-i] = temp;
	}
}
bool ReorderList(Sqlist &L, int m, int n){
	Reverse(L, 0, m+n-1);
	Reverse(L, 0, n-1);
	Reverse(L, n, m+n-1);
}

/* 
 * 2.2.9 SearchElem
 *   DESCRIPTION: Search a element with value x in a ordered Sqlist L,
 *				  if found, return true and exchange its with the element behind it;
 *				  if not found, return false insert it in this Sqlist L and make it ordered
 *   INPUTS: Sqlist &L
 *   OUTPUTS: new Sqlist &L
 *   RETURN VALUE: 1-found; 0-not found;
 *   SIDE EFFECTS: None
 */
bool SearchElem(Sqlist &L, int x){
	int i, temp;
	for (i=0; i<=L.length-1; ++i){
		if (L.data[i]<x) continue;
		// found
		else if (L.data[i]==x){
			temp = L.data[i];
			L.data[i] = L.data[i+1];
			L.data[i+1] = temp;
			printf("\nValue x is found in the Sqlist, do the operation of exchanging successfully\n");
			return true;
		}
		else if (L.data[i]>x){
			int j;
			L.length++;
			//shift right one unit from L.data[i]
			for (j=L.length-1; j>i; j--){
				L.data[j] = L.data[j-1];
			}
			//insert x
			L.data[i]=x;
			printf("\nValue x is not found in the Sqlist, insert it successfully\n");
			return false;
		}
	}
}

#endif


