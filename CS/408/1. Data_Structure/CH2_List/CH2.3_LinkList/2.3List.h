#ifndef _2_3_LIST_H_
#define _2_3_LIST_H_

#include "LinkList.h"

/*------------------------Problem Variables---------------------*/

/*------------------------Problem Function---------------------*/
bool GetReverseElem(LinkList L, int k);
bool GetPostfixIdx(LinkList str1, LinkList str2);

/* 
 * 2.3.21 GetReverseElem
 *   DESCRIPTION: Output data of the reversed index i element in the LinkList l
 *   INPUTS: LinkList l
 *   OUTPUTS: the value of the reversed index i element
 *   RETURN VALUE: 1-successful; 0-fail
 *   SIDE EFFECTS: None
 */
 
/* Algorithm: 1) traverse the Linklist to get the length of it, recorded as length;
			  2) use length-k to get the index of the output LNode
*/
bool GetReverseElem(LinkList L, int k){
	int length = GetLinkListLength(L);
	while (k<=0 || k>length-1) {
		printf("Invalid input k!\n");
		//printf("Enter the reversed k element you want to find:\n");
		//scanf("%d", &k);
		return false;
	} 
	int i=1;
	LNode *p = L;
	while(i+k<=length){
		p=p->next;
		i++;
	}
	printf("The reversed k element is %d\n",p->data);
	return true;
}

/* 
 * 2.3.22 GetPostfixIdx
 *   DESCRIPTION: Output index i of the first same element of the LinkList l1 & l2
 *   INPUTS: LinkList l1, l2
 *   OUTPUTS: index i
 *   RETURN VALUE: 1-successful; 0-fail
 *   SIDE EFFECTS: None
 */
 
/* Algorithm: 1) use two LNode p1,p2 to traverse the Linklist str1 and str2 and compare its value
			  2) use start to record the start idx of the same postfix, end to record the end
			  3) idx of the same postfix 
*/

bool GetPostfixIdx(LinkList str1, LinkList str2){
	int idx=1, start=1, end=1;
	LNode *p1=str1->next, *p2=str2->next;
	printf("2.3.22 STRAT!------\n");
	//printf("p1 & p2 are %f, %f\n",p1, p2);
	printf("p1->data & p2->data are %d, %d\n",p1->data, p2->data);
	while(p1!=NULL && p2!=NULL){
		printf("to 1\n");
		printf("Now idx is %d\n",idx);
		while(p1->data!=p2->data){
			p1=p1->next;
			p2=p2->next;
			idx++;
		}
		printf("to 2\n");
		printf("Now idx is %d\n",idx);
		start = idx;
		printf("Now start is %d\n",start);

		while(p1->data==p2->data && p1!=NULL && p2!=NULL){
			printf("same data %d\n ",p1->data);
			p1=p1->next;
			p2=p2->next;
			idx++;
		}
		end = idx;
		printf("to 3\n");
		printf("Now idx is %d\n",idx);
		printf("Now end is %d\n\n",end);
		
	}
	printf("Now idx is %d\n",idx);
	
	printf("The start idx of the same postfix is: %d",start);
	return true;
}
#endif

