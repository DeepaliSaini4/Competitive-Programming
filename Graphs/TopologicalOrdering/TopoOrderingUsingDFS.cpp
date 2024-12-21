//Topological order is a linear arrangement of nodes in a directed graph where for every directed edge from node A to node B, A comes before B in the ordering.
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>vis;
vector<int>topo;
void dfs(int node){
    vis[node]=1;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
         }    
    }
    topo.push_back(node);
}
signed main(){
    int n,m;
    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    for(int i=1;i<n;i++){
        if(!vis[i])
        dfs(i);
    }
    reverse(topo.begin(),topo.end());
    for(auto v:topo){
        cout<<v<<" ";
    }
}
/*
Every node that could be reached from the gievn node is reached through dfs and then stored first and later the array is reversed
*/