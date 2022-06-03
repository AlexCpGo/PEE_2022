#include <stdio.h>
#include "2.h"

Sqlist l;
int testflag = 0;
/* Function Declaration and global element definition*/
void test(); 
void InitSqlist(Sqlist &l);
void printInfo(Sqlist &l, int testflag);


int main(){
	//testflag = 1;
	testflag = 4;
	test();
	return 0;
}

void test(){	
	InitSqlist(l);
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
	}

	
	return;
}

void InitSqlist(Sqlist &l){
	int idx;
	/* Initialization on the Sqlist l1 */
	l.length = 8;
	l.data[0] = 1;
	int i;
	for(i=1; i<=7; ++i){
		//l.data[i] = (i+1)*(i+1);
		//l.data[i] = 3;
		l.data[i] = l.data[i-1]+2*i;
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

void printInfo(Sqlist &l, int testflag){
	int idx;
	printf("\n\nFor qustion 2.%d, after the operation:\n", testflag);
	printf("  The length of Sqlist l is %d\n",l.length);
	printf("  Sqlist l is ");
	for (idx=0; idx<=l.length-1; ++idx){
		printf("%d ",l.data[idx]);
	}
}
	

