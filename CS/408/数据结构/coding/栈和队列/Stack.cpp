#include <iostream>
#define maxSize 100 

// Update top of the stack when data into stack
// Sequential Stack
typedef struct
{
	int  data[maxSize];
	int top;
} SqStack;
// Linked Stack
typedef struct LNode
{
	int data;
	struct LNode *next;
} LNode;

/// Sequential Stack
// Innitialize stack
void initStack(SqStack &st)
{
	st.top = -1;
}
// Judge whether the stack is empty
int isEmpty(SqStack st)
{
	if (st.top == -1)
		return 1;
	else
		return 0;;
}

// Push
/*When the stack is full, the push operation can not be exercuted*/  
int push(SqStack &st, int x)
{
	if (st.top == maxSize-1) 
		return 0;
	++(st.top);
	st.data[st.top] = x;
	return 1;
}

// Pop
int pop(SqStack &st, int &x)
{
	if (st.top == -1)
		return 0;
	x = st.data[st.top];
	--(st.top;
	return 1;
}

// Simplified version
/*
int stack[maxSize];
int top = -1;

stack[++top] = x;
x = stack[top--];
*/

// Linked Stack
int isEmpty(LNode *lst)
{
	if(lst->next == NULL)
		return 1;
	else
		return 0;
}

/*No limit of return value for no limit of the size of the stack*/
void push(LNode *lst, int x)
{
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;
	
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}

int pop(LNode *lst, int &x)
{
	LNode *p;
	if (lst->next ==NULL)
		return 0;
	
	p = lst->next;
	x = p->data;
	lst->next = p->next;
	free(p);
	return 1; 
}


// Application of Sequential Stack
// Match the Brackets
int match_brackets(char exp[],int n)
{
    char stack[MaxSize];
    int top = -1;

    int i;
    for (i=0; i<n; i++) {
        if (exp[i] = "(")
            stack[++top] = "(";
        else if (exp[i] = ")") {
            if (top == -1)
                return 0; // False condition
            else
                --top; // pop a "(" out of the stack
        }
    }
    if (top == -1)
        return 1;
    else
        return 0;
}


// Simple Calculator
int op(int a, char Op, int b)
{
    if (Op == "+") return a+b;
    if (Op == "-") return a-b;
    if (Op == "*") return a*b;
    if (Op == "/"){
        if (b==0)
            cout<<"ERROR"<<endl;
            return 0;
        else
            return a/b;
    }
}


int com(char exp[])
{
    int i, a, b, result;
    char Op;
    int stack[MaxSize];
    int top = -1;

    for (i=0; exp[i]!="\0"; ++i) {
        if (exp[i]>="0" && exp[i]<="9")
            stack[++top]=exp[i]-"0";    //ASCII operation to get int value
        else {
            Op = exp[i];
            b = exp[top--];
            a = exp[top--];
            result = op(a,Op,b);
            stack[++top] = result;
        }
    }
    return stack[top];
}












