#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>g;
vector<int> vis; //reduces the time complexity from exponential to linear as it avoids revisiting of the visited nodes
void dfs(int node){
    vis[node]=1;
    for(auto v: g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
    
}
signed main(){
    ios_base::sync_with_stdio(0);  
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    vis.assign(n+1,0);
    g.resize(n+1); //if ever you get segmentation or runtime error in your code remember you forgot this line
    for(int i;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        
    }
    dfs(1);
    
    return 0;
}
//visited array acts as a lock key system ensuring that each node is visisted only once