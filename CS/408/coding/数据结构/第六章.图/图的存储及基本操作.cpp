//###### Adjacent Matrix Method
#define MaxVertexNum 100
#define INFINITY 0x3ffffff//“某个很大的int值”
typedef char VertexType;
typedef int EdgeType; //int:4B; if without weight: bool EdgeType: 1B
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph;

/*
Simplied version:
int G[MaxVertexNum][MaxVertexNum];
#include<algorithm>
1)int G[MaxVertexNum][MaxVertexNum]; //Fill with 0
2)fill(G[0], G[0]+MaxVertexNum*MaxVertexNum, INF) //Fill with INF
*/

//###### Adjacent list Method
// Nodes after Edge pointed to/connect to
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    //InfoType info;
}ArcNode;

// Vertex Node that is stored in the first position 
typedef struct VNode{
    VertexType data;
    ArcNode *first;
}VNode, AdList[MaxVertexNum];

// Graph with Adjacent list Method
typedef struct{
    AdList vertices;
    int vexnum,arcnum;
}ALGraph;

//###### Cross list structure: Directed Graph
typedef struct CroArcNode{
    int tailvex;
    int headvex;
    struct CroArcNode *hlink;
    struct CroArcNode *tlink;
    //int info;
}CroArcNode;

typedef struct CroVNode{
    VertexType data;
    struct CroVNode *fisrtin;
    struct CroVNode *fisrtout;
}CroVNode;


//###### Adjacency multilist: Undirected Graph
