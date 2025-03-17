

void dfs(int node,int prev,int dep){
    par[node] = prev;
    depth[node] = dep;
    //building the lifting structure
    for(int i=1;i<20;i++){
        par[node][i] = par[par[node][i-1]][i-1];
    }
    for(auto v:neigh[node]){
        if(v!=prev){
            dfs(v,node,dep+1);
        }
    }
}

//query processing
int lca(int u,int v){
    if(depth[u]<depth[v]) swap(u,v); //now u is the one with more depth 
    for(int i=19;i>=0;i--){
        if((depth[u]-depth[v]) & (1<<i)){
            u = par[u][i];
        }
    }
    if(u==v) return u;
    for(int i=19;i>=0;i--){
        if(par[v][i] != par[u][i]){
            v = par[v][i];
            u = par[u][i];
        }
    }
    return par[u][0];
}
//tc = O(nlogn)+logn build part + query part = O((N + Q)logN)
