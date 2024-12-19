#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>g;
vector<int> vis;
void dfs(int node, int comp_num){
    vis[node]=comp_num;
    for(auto v: g[node]){
        if(!vis[v]){
            dfs(v,comp_num);
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
    int num_comp = 0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            num_comp++;
            dfs(i,num_comp);
        }
    }
    cout<<num_comp<<endl;
    vector<vector<int>> components;
    components.resize(num_comp+1);
    for(int i=0;i<n;i++){
        cout<<i<<": "<<vis[i]<<endl;
        components[vis[i]].push_back(i);
    }
    return 0;
}

/*
test case with ans:
9 7
1 2
1 4
2 8
4 8
5 6
6 7
3 9
3
0: 0
1: 1
2: 1
3: 2
4: 1
5: 3
6: 3
7: 3
8: 1

*/