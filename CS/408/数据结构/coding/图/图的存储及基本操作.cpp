//###### Adjacent Matrix Method
#define MaxVertexNum 100
#define INFINITY “最大的int值”
typedef char VertexType;
typedef int EdgeType; //int:4B; if without weight: bool EdgeType: 1B
typedef struct{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
}MGraph;

//###### Adjacent list Method
// Directional Edge
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *next;
    //InfoType info;
}ArcNode;

// Vertex
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
