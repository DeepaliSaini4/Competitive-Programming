//Q-You are given a tree consisting of n nodes. Find the center of a tree. If there exist multiple centers, print -1
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<vector<int>> g;
vector<int> par;
vector<int> dep;

void dfs(int node, int parent, int depth){
    par[node] = parent;
    dep[node] = depth;
    for(auto v: g[node]){
        if(v!=parent){
            dfs(v,node,depth+1);
        }
    }
}

void solve(){
    //Apply dfs from any random node X
    int X = 1;
    dfs(1,0,0);

    //Find the farthest node Y from X
    int Y_max = 1; 
    for(int i=2; i<=n; i++){
        if(dep[i] > dep[Y_max]) Y_max = i;
    }

    //Apply dfs from Y
    dfs(Y_max,0,0);

    //Find the farthest node Z from Y
    int Z_max = 1;
    for(int i = 2; i<=n; i++){
        if(dep[i] > dep[Z_max]) Z_max=i;
    }

    // The distance Y - Z is ther diameter of the tree
    int dia = dep[Z_max];

    if(dia % 2 != 0) cout << "-1" << '\n'; //Odd dia contains 2 centers
    else{
        int center = Z_max;
        for(int i = 0; i<dia/2 ; i++){
            center = par[center];
        }
        cout << center << '\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n ;
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    } 
    par.resize(n+1);
    dep.resize(n+1);
    solve();
    return 0;
}