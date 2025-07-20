#include <bits/stdc++.h>
using namespace std;

void bfs(vector<int>&ans, vector<vector<int>>&adj,vector<bool>&visited,int src){
    queue<int>q;
    q.push(src);
    visited[src] = 1;
    ans.push_back(src);
    while(!q.empty()){
       int node =  q.front();
       q.pop();
       for(auto it:adj[node]){
           if(!visited[it]){
               visited[it] = 1;
               ans.push_back(it);
               q.push(it);
           }
       }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int m,n;//vertices and edges
    cin>>m>>n;
    vector<vector<int>>adj(m);
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>ans;
    vector<bool>visited(m,0);
    bfs(ans,adj,visited,1);
    for(auto it:ans){
        cout<<it<<" ";
    }
    
    return 0;
}
