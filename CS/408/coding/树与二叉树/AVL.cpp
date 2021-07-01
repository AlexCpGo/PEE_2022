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
// Do RR operation then LL operation

