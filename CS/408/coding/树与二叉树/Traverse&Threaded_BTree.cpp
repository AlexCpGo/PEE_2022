#include <BinaryTree.hpp>
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTNode;

typedef struct LinkNode{
    BiTNode *data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

typedef struct ThreadNode{
    ElemType data;
    struct BiTNode *lchild, *rchild;
    int ltag, rtag;
}BiTNode, *BiTNode;

ThreadNode *pre = NULL; //Inital global variable *pre

void visit(ThreadNode *q)
{
    if(q->lchild == NULL){
        q->lchild = pre;
        q->ltag = 1;
    }

    if(pre != NULL && pre->rchild = NULL){
        pre->rchild = q;
        pre->rtag = 1;
    }
    pre = q;
}

/* 1.PreOrder Traverse */
void PreOrder(BiTree T)
{
    if(T != NULL){
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

// PreOrder Threaded Traverse Tree
void PreThread(ThreadTree T)
{
    if(T != NULL){
        visit(T);
        if(T->ltag == 0) PreThread(T->lchild);
        PreThread(T->rchild);
    }
}

void CreatePreThread(ThreadTree T)
{
    pre = NULL;
    if(T != NULL){
        PreThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}


/* 2.InOrder Traverse */
void InOrder(BiTree T)
{
    if(T != NULL){
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}


// InOrder Threaded Traverse Tree
void InThread(ThreadTree T)
{
    if(T != NULL){
        InThread(T->lchild);
        visit(T);
        InThread(T->rchild);
    }
}

void CreateInThread(ThreadTree T)
{
    pre = NULL;
    if(T!=NULL){
        InThread(T);
        if (pre->rchild==NULL)
            pre->rtag = 1;
    }
}


/* 3.PostOrder Traverse*/ 

void PostOrder(BiTree T)
{
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}

//PostOrder Traverse to get depth of the BTree
int treeDepth(BiTree T)
{
    if(T == NULL) return 0;
    else{
        int l = treeDepth(T->lchild);
        int r = treeDepth(T->rchild);

        return l>r? l+1: r+1;
    }
}

//PostOrder Threaded Traverse Tree
void PostThread(ThreadTree T)
{
    if(T!=NULL){
        PostThread(T->lchild);
        PostThread(T->rchild);
        visit(T);
    }
}

void CreatePostThread(ThreadTree T)
{
    pre = NULL;
    if(T != NULL){
        PostThread(T);
        if (pre->rchild == NULL)
            pre->rtag = 1;
    }
}

/* 4.LevelOrder Traverse: Use LinkQueue to traverse */
void LevelOrder(BiTree T)
{
    LinkQueue Q;
    InitQueue(Q);
    BiTree p;
    EnQueue(Q, T);
    while(!isEmpty(Q)){
        DeQueue(Q, p);
        visit(p);
        if(p->lchild != NULL)
            EnQueue(Q, p->lchild);
        if(p->rchild != NULL)
            EnQueue(Q, p->rchild);
    }
}


// Use Threaded BTree to find the pre_node and next_node
// 1) p->rtag == 1, next = p->rchild
// 2) p-rtag == 0, next = the most left one node in the right subtree of p
ThreadNode *Firstnode(ThreadNode *p)
{
    while(p->ltag == 0) p = p->lchild;
    return p;
}

ThreadNode *Nextnode(ThreadNode *p) 
{
    if(p->tag == 0) return Firstnode(p->rchild);
    else return p->rchild
}

void InOrder(ThreadNode *T)
{
    for (ThreadNode *p=Firstnode(T); p!=NULL; p=Nextnode(P)){
        visit(p);
    }
}
