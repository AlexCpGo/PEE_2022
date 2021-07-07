// BFS to find the SR
void BFS_MIN_Distance(Graph G, int u)
{
    for (i=0; i<G.vexnum; ++i){
        d[i] = ∞；
        path[i] = -1;
    }
    d[u] = 0;
    visited[u] = true;
    EnQueue[Q, u];
    while(!isEmpty(Q)){
        DeQueue(Q, u);
        for(w=FirstNeighbor(G, u); w>=0; w=NextNeighbor(G, u, w)){
            if (!visited[w]){
                d[w] = d[u] + 1; // Each edge is with cost 1;
                path[w] = u;
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

// Dijkstra Algorithm to find the SR







// Floyd Algorithm to find the SR
// Time Complexity: O(|V^3|), Space Complexity: O(|V^2|);
for (int k=0; k<n; k++){ // n = |vertex|; consider vk to be the transit point
    for (int i=0; i<n; i++){ // Adjacency matrix A[i][j]
        for (int j=0; j<n; j++){
            if (A[i][j] > A[i][k]+A[k][j]){
                A[i][j] = A[i][k]+A[k][j];
                path[i][j]=k;
            }
        }
    }
}
    
