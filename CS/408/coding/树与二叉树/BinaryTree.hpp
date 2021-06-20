/* Definion of BinaryTree */
#define MaxSize 100

// Sequential Storage Node: only useful for Complete binary tree.
struct ElemType{
    int value;
};
typedef struct SBTreeNode{
    ElemType value;
    bool isEmpty;
}SBTreeNode;

//A BTree with height h need at least 2^h - 1 STreeNode --> Low Density of Memory usage
STreeNode t[MaxSize];


for (int i=0; i<MaxSize; i++){
    t[i].isEmpty = True;
}

t[0] = NULL; // To make the root node to store in t[1]


// Linked Storage Node
struct ElemType{
    int value;
};
typedef struct LBTreeNode{
    ElemType data;
    struct LBTreeNode *lchild, *rchild;
    //struct LBTreeNode *parent;
} LBTreeNode, *LBTreeNode;

LBTreeNode root = NULL;

