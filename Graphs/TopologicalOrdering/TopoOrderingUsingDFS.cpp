//Topological order is a linear arrangement of nodes in a directed graph where for every directed edge from node A to node B, A comes before B in the ordering.
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>g;
vector<int>vis;
vector<int>topo;
int n,m;

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

    return 0;
}
/*
Every node that could be reached from the given node is reached through dfs and then stored first and later the array is reversed
*/