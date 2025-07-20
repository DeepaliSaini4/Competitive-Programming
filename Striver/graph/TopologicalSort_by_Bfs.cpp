#include <bits/stdc++.h>
using namespace std;

void dfs(stack<int>&s,vector<vector<int>>&adj,vector<int>&vis,int node){
    vis[node] = true;
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(s,adj,vis,it);
        }
    }
    s.push(node);
}

int main() {
	// your code goes here
	int m,n;
	cin>>m>>n;
	vector<vector<int>>adj(m+1);
	for(int i=0;i<m;i++){
	    int a,b;
	    cin>>a>>b;
	    adj[a].push_back(b);
	}
	stack<int>s;
	vector<int>vis(m+1,0);
	for(int i=1;i<=m;i++){
	    if(!vis[i])
	        dfs(s,adj,vis,i);
	}
	
	while(!s.empty()){
	   cout<<s.top()<<" ";
	   s.pop();
	}
	return 0;

}
