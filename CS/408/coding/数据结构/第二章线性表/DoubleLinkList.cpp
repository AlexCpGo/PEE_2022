typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
}DNode, *DLinkList;

bool InitDLinkList(DLinkList &L)
{
    L = (DNode *) malloc(sizeof(DNode));
    if(L==NULL) return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

//Insert DNode s following DNode p
bool InsertNextDNode(DNode *p, DNode *s)
{
    if (p==NULL || s==NULL) return false;
    s->next = p->next;
    if(p->next != NULL){
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

//Delete the DNode behind p
bool DeleteNextDNode(DNode *p)
{
    if(p==NULL) return false;
    DNode *q = p->next;
    if(q==NULL) return false;
    p->next = q->next;
    if(q->next != NULL){
        q->next->prior = p;
    }
    free(q);
    return true;
}

//Destroy DList
void DestoryDLinkList(DLinkList &L)
{
    while(L->next != NULL){
        DeleteNextDNode(L);
    }
    free(L);
    L=NULL;
}