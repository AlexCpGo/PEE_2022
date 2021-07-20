typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

bool InitList(LinkList &L)
{
    L = (LNode *) malloc(sizeof(LNode));
    if (L==NULL){
        return false;
    }
    L->next == NULL;
    //L->next = L; //Single Linked Circular List
    return true;
}

bool Empty(LinkList L)
{
    return (L==NULL);
}

bool InsertNextNode(LNode *p, ElemType e)
{
    if(p == NULL) return false;
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if(s == NULL) return false;
    s-data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//LinkListInsert with head node
bool ListInsert(LinkList &L, int i, ElemType e)
{
    if(i<1) return false;
    /*
    Without head node:

    if (i==1){
        LNode *s = (LNode *)malloc(sizeof(LNode));
        s->data = e;
        s->next = L;
        L = s;
        return true;
    }
    */
    LNode *p;
    int j=0;
    p = L;
    while(p!==NULL && j<i-1){
        p = p->next;
        j++;
    }
    return InsertNextNode(p, e);
}

bool InsertPrioNode(LNode *p, LNode *s){
    //Copy the data into the new allocated node
    if(p==NULL || s==NULL) return false;
    s->next = p->next;
    p->next = s;
    ElemType temp = p->data;
    p->data = s->data; 
    s->data = temp;
    return true;
}

// Delete the ith element on the list
bool ListDelete(LinkList &L, int i, ElemType &e){
    if(i<1)
        return false;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL && j<i-1){
        p=p->next;
        j++;
    }
    if(p==NULL) return false;
    if(p->next == NULL) return false;
    LNode *q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

bool DeleteNode(LNode *p)
{
    if(p==NULL) return false;
    LNode *q = p->next;
    p->data = p->next->data;
    p->next = q->next;
    free(q);
    return true;
}

//Get the ith element of the list
LNode *GetElem(LinkList L, int i)
{
    if(i<0) return NULL;
    LNode *p;
    int j=0;
    p=L;
    while(p!=NULL && j<i){
        p=p->next;
        j++;
    }
    return p;
}

//Build the linklist by inserting Node to the head
LinkList List_HeadInsert(LinkList &L)
{
    LNode *s;
    int x;
    L= (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    scanf("%d", &x);
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}


//Build the linklist by inserting Node to the tail
LinkList List_TailInsert(LinkList &L)
{
    int x;
    L= (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    LNode *s, *r=L;
    scanf("%d", &x);
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    return L;
}