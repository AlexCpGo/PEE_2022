//5叉排序树的结点定义
struct Node{
    ElemType keys[4];
    struct Node *child[5];
    int num;
}