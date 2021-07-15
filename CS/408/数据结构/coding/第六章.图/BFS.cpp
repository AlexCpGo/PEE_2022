#define MAX_VERTEX_NUM 100
bool visited(MAX_VERTEX_NUM);
void BFSTraverse(Graph G)
{
    for(i=0; i<G.vexnum; i++){
        visited[i] = false;
    }
    InitQueue(Q);
    for(i=0; i<G.vexnum;i++){
        if(!visited[i]{
            BFS(G, i);
        })
    }
}

void BFS(Graph G, int v)
{
    visit(v);
    visited[v] = true;
    EnQueue(Q, v);
    while(!isEmpty(Q)){
        DeQueue(Q, v);
        for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)){
            if(!visited[w]){
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    } 
}