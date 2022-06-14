#include <stdio.h>
#include "List.h"

Sqlist l, l1, l2;
int testflag = 0;
/* Function Declaration and global element definition*/
void test(); 
void InitSqlist(Sqlist &l);
void TwoList(Sqlist &l1, Sqlist &l2);
void printInfo(Sqlist &l, int testflag);


int main(){
	//testflag = 1;
	testflag = 9;
	test();
	return 0;
}

void test(){	
	InitSqlist(l);
	
	/* For 2.7 */
	//TwoList(l1,l2);
	/* Initialize the new Sqlist L for the merged result */
	//l.length = l1.length + l2.length;
	
	/*------------test part------------*/
	switch (testflag){
		case 1: DeleteMin(l);
				printInfo(l, testflag);
				break;
				
		case 2: ReverseSqlist(l);
				printInfo(l, testflag);
				break;
				
		case 3: DeleteElem(l, 3);
				printInfo(l, testflag);
				break;
				
		case 4: DeleteOrdRange(l, 10, 30);
				printInfo(l, testflag);
				break;			
				
		case 5: DeleteRange(l, 30, 5);
				printInfo(l, testflag);
				break;
					
		case 6: DeleteRepeat(l);
				printInfo(l, testflag);
				break;	
				
		case 7: MergeList(l1, l2, l);
				printInfo(l, testflag);
				break;	

		case 8: ReorderList(l, 5, 3);
				printInfo(l, testflag);
				break;

		case 9: SearchElem(l, 75);
				printInfo(l, testflag);
				break;	
	}

	
	return;
}

void InitSqlist(Sqlist &l){
	int idx;
	/* Initialization on the Sqlist l1 */
	l.length = 8;
	l.data[0]=1;
	int i;
	for(i=1; i<=2; ++i){
		//l.data[i] = (i+1)*(i+1);
		//l.data[i] = 3;
		l.data[i] = l.data[i-1]+2*i;
	}
	
	for(i=3; i<=5; ++i){
		//l.data[i] = (i+1)*(i+1);
		//l.data[i] = 3;
		l.data[i] = 7;
	}
	
	for(i=5; i<=7; ++i){
		//l.data[i] = (i+1)*(i+1);
		//l.data[i] = 3;
		l.data[i] = 50+i*i;
	}
	//l.data[5] = 4;
	
	printf("Initially:\n");
	printf("  The length of Sqlist l is %d\n",l.length);
	printf("  Sqlist l is ");
	for (idx=0; idx<=l.length-1; ++idx){
		printf("%d ",l.data[idx]);
	}
	return;
}

void TwoList(Sqlist &l1, Sqlist &l2){
	int i;
	/* Initialization on the Sqlist l1,l2 */
	l1.length = 6;
	l2.length = 3;
	for (i=0; i<=l1.length-1; ++i){
		l1.data[i]=i*i+2;
	}
	for (i=0; i<=l2.length-1; ++i){
		l2.data[i]=i*2+1;
	}

	printf("Initially:\n");
	printf("  The length of Sqlist l1 is %d\n",l1.length);
	printf("  Sqlist l1 is ");
	for (i=0; i<=l1.length-1; ++i){
		printf("%d ",l1.data[i]);
	}

	printf("\n  The length of Sqlist l2 is %d\n",l2.length);
	printf("  Sqlist l2 is ");
	for (i=0; i<=l2.length-1; ++i){
		printf("%d ",l2.data[i]);
	}
	return;
}

void printInfo(Sqlist &l, int testflag){
	int idx;
	printf("\n\nFor qustion 2.%d, after the operation:\n", testflag);
	printf("  The length of Sqlist l is %d\n",l.length);
	printf("  Sqlist l is ");
	for (idx=0; idx<=l.length-1; ++idx){
		printf("%d ",l.data[idx]);
	}
}
	

