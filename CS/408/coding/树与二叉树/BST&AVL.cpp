// BST Searching use loop
BSTNode *BST_Search(BiTree T, ElemType key)
{
    while(T!=NULL && key!=T->data){
        if(key<T->data) T = T->lchild;
        else T = T->rchild;
    }
    return T;
}

// BST Seaching Recursively
BSTNode *Recur_BST_Search(BiTree T, ElemType key)
{
    if (T==NULL) return 0; // fail
    else if (key == T->data) return T;
    else if (key<T->data) {
        Recur_BST_Search(BiTree T->lchild, ElemType key);
    }
    else if (key>T->data) {
        Recur_BST_Search(BiTree T->rchild, ElemType key);
    }
}

// BST Inserting
int BST_Insert(BiTree &T, KeyType k)
{
    if (T = NULL){
        T = (BiTree)malloc(sizeof(BSTNode));
        T->key = k;
        T->lchild = T->rchild = NULL;
        return 1;
    }

    else if(k==T->key) return 0;

    else if(k<T->key){
        return BST_Insert(BiTree T->lchild, KeyType k);
    }
    else if(k>T->key){
        return BST_Insert(BiTree T->rchild, KeyType k);
    }
}

// BST Creating
void Creat_BST(BiTree &T, KeyType str[], int n){
    T = NULL;
    int i = 0;
    while (i<n){
        BST_Insert(T, str[i]);
        i++;
    }
}

// AVL
// LL
// f is father, p is left child, gf is the father of f
f->lchild = p->rchild;
p->rchild = f;
gf->lchild/rchild = p;

// RR
// f is father, p is right child, gf is the father of f
f->rchild = p->lchild;
p->lchild = f;
gf->lchild/rchild = p;

// LR: The left child of A's right child
// Do LL operation then RR operation

// RL: The right child of A's left child
// Do RR operation then LL operation0