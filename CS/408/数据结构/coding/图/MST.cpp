//###### Minimum-Spanning-Tree(MST)
// General Algorithm
// two list for help: 1)isjoint[n] 2)lowcost[n]  
GENERIC_MST(G)
{
    T = NULL;
    while T has not become a Spanning Tree:
        do to find an edge(u, v) with the lowest cost, meanwhile ensure that doesnt create a loop after joining in T;
            T = T ∪ (u, v);
}

//### Prim Algorithm
void Prim(G, T)
{
    T = an empty set;
    U = {w};
    while (V-U) != empty set){
        set (u, v) that u∈U and v∈（V-U), meanwhile the edge with the lowest cost;
        U = U ∪ {v};
    }
}


//### Kruskal Algorithm 
void Kruskal(V, T)
{
    T = V;
    numS = n;
    while (numS>1) {
        select the edge(u,v) with the lowcost from E;
        if (v&u ∈ different Connected Components in T){
            T = T ∪ {(v, u)};
            numS--;
        }
    }
}