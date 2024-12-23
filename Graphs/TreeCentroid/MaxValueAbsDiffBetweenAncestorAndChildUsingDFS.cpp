//For a given tree calculate max (abs(val[x]-val[y])) where y is the ancestor of x.
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<vector<int>>g;
int ans[100100];
int val[100100];


void dfs(int node,int par, int maxval,int minval){
    ans[node] = max(abs(maxval-val[node]), abs(minval-val[node]));
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node,max(maxval,val[node]),min(minval,val[node]));
        }
    }
}

void solve(){
    dfs(1,0,-1e9,1e9);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    cin >> n;
    g.resize(n);
    
    // Input node values
    for (int i = 1; i <= n; ++i) {
        cin >> val[i];
    }

    for(int i=0;i<n;i++){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    solve();
    return 0;
}