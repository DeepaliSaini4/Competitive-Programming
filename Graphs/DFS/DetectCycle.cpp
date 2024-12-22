#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m;
vector<vector<int>>g;
vector<int> vis;
bool is_cycle_present = false;

void dfs(int node, int par){
    vis[node]=1;
    for(auto v: g[node]){
        if(!vis[v]){
            dfs(v,node);
        }
        else if(v!=par) {
            //cycle is present
            is_cycle_present = 1;
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    g.resize(n+1); 
    for(int i;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }

    cout << (is_cycle_present ? "Cycle is present" : "No cycle detected") << endl;
    return 0;
}
