bool visited[MAX_VERTEX_NUM];
void DFS(Graph G, int v){
    visit(v);
    visited[v] = true;
    for(w=FirstNeighbor(G, v); w>=0; w=NextNeighbor(G, v, w)){
        if(!visited[w]){
            DFS(G, w);
        }
    }
}

void DFSTraverse(Graph G){
    for(v=0; v<G.vexnum; ++v){
        visited[v] = false;
    }
    for(v=0; v<G.vexnum; ++v){
        if(!visited[v]{
            DFS(G, v);
        })
    }
}