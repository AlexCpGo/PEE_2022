#include <stdio.h>
#include "2.3List.h"

LinkList l, str1, str2;	
int k, testflag = 0, PSflag = 3;// PS: Problem Set


/* Function Declaration and global element definition*/
void test(); 
void InitLinkList(LinkList &l);
void printInfo(LinkList l, int testflag);


int main(){
	//testflag = 1;
	testflag = 22;
	test();
	//free(1);
	free(str1);
	free(str2);
	return 0;
}

void test(){
	//InitLinkList(l);
	
	/* For 2.2.7 */
	//TwoList(l1,l2);
	/* Initialize the new Linklist L for the merged result */
	//l.length = l1.length + l2.length;
	
	/*------------test part------------*/
	
	switch (testflag){
		case 0: printInfo(l, testflag);
				break;
		
		case 21:printf("Enter the reversed k element you want to find:\n");
				scanf("%d", &k);
				GetReverseElem(l, k);
				//printInfo(l, testflag);
				break;
				
		case 22:InitLinkList(str1);
				InitLinkList(str2);
				GetPostfixIdx(str1, str2);
				//printInfo(l, testflag);
				printf("2.3.22 FINISH!------\n");
				break;
		
	}
	
		
	
	return;
}

void InitLinkList(LinkList &l){	
	List_TailInsert(l);

	return;
}



void printInfo(LinkList l, int testflag){
	int length;
	printf("\nAfter the operation of qustion 2.%d.%d, LinkList l is:\n", PSflag, testflag);	
	LNode *p = l->next; // l is the Lead Node instead of the first Element Node
	
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
		length++;
	}
	printf("\nThe length of Linklist l is %d\n",length);
	printf("-------------Problem Solved-------------\n");
}

	

