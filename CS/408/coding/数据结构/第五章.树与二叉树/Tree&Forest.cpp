// Three types of the tree representation
// 1.Parents
#define Max_TREE_SIZE 100
typedef struct{
    ElemType data;
    int parent;
}PTNode;

typedef struct{
    PTNode nodes[MAX_TREE_SIZE];
    int n;
}PTree;

// 2.Children
// Use linked list to link all the children of the parent one by one

// 3.Children & Brother
typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild, *nextsibling;
}CSNode, *CSTree;

// PreOrder Traversal of tree: depth first Traverse
void PreOrder(TreeNode *R){
    if (R != NULL){
        visit(R);
        while(R还有下一个子树T)
            PreOrder(T);
    }
}

// PostOrder Traversal of tree: depth first Traverse
void PostOrder(TreeNode *R){
    if (R != NULL){
        while(R还有下一个子树T)
            PreOrder(T);
        visit(R);
    }
}

// LevelOrder: Use Queue! Breadth first Traverse


// Application of Tree: Disjoint-set data structure
#define SIZE 100
int     UFSets[SIZE];

void Intial(int S[]){
    for(int i=0; i<size; i++){
        S[i] = 1;
    }
}

int Find(int S[], int x){
    while(S[x]>0)
        x = S[x];
    return x;
}

void Union(int S[], int Root1, int Root2){
    S[Root2] = Root1;
}