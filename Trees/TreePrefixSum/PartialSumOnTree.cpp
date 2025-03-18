/*
Description
You are given a tree with N nodes. Initially, all the nodes values is zero. You have to perform Q queries - 3 space-separated integers x, y, z → add z to all the nodes on 
the shortest path from x to y.
After performing all the queries print the final value of nodes 1,2,….n.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

vector<vector<int>>g;
vector<vector<int>>par;
vector<int>dep;
vector<int>pars;

void dfs(int node,int parent,int depth){
    par[node][0] = parent;
    dep[node] = depth;

    for(int i=1;i<=19;i++){
        if(par[node][i-1]!=-1){
            par[node][i] = par[par[node][i-1]][i-1];
        }else{
            par[node][i] = -1;
        }
    }
    for(auto v:g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}

int lca(int u,int v){
    if(dep[u]<dep[v]) swap(u,v);

    for(int i = 19;i>=0;i--){
        if((dep[u]-dep[v]) & (1<<i)){
            u = par[u][i];
        }
    }
    if(u==v) return u;

    for(int i=19;i>=0;i--){
        if(par[u][i]!=par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

 void addz(int x,int y,int z){
        pars[x] +=z;
        pars[y] +=z;
        int lc = lca(x,y);
        pars[lc]-=z;
        if (par[lc][0] != -1) pars[par[lc][0]] -= z;
    }

void pushall(int node,int parent){
    for(auto v:g[node]){
        if(v!=parent){
            pushall(v,node);
        }
    }
        if (par[node][0] != -1) pars[par[node][0]] += pars[node];
}

void solver(){
    int n;
    cin>>n;

    par.assign(n+1,vector<int>(20,-1));
    dep.assign(n+1,0);
    pars.assign(n+1,0);

    g.resize(n + 1);
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1,0);

    int q;
    cin>>q;
    while(q--){
        int x,y,z;
        cin >> x >> y >> z;
        addz(x,y,z);
    }

    pushall(1,0);
    for(int i=1;i<=n;i++) cout<<pars[i]<<" ";
    cout<<'\n';
    par.clear();
    dep.clear();
    pars.clear();
    g.clear();

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();

    return 0;
}
