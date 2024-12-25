/*
Description
You have given an undirected graph G with N nodes and M edges. You've to answer Q queries. Each query is either of the following two types:

1 X: Print the size of the connected components containing node X.
2 X Y: Print ‘YES’ (without quotes) if node X and Y belong to the same connected component, else print ‘NO’ (without quotes).
Input Format
The first line of input contains three space-separated integers N, M, and Q (1 ≤ N, M, Q ≤ 105).
Next M lines contain two space-separated integers u and v (1 ≤ u, v ≤ N).
Each of the next Q lines contains queries of one of the types as described in the statement.

Output Format
Print Q lines as the answer to the Q queries, each on a new line.

Sample Input 1
6 5 5
1 2
2 3
1 3
4 4
5 6
1 2
1 4
2 3 4
1 5
2 5 6
Sample Output 1
3
1
NO
2
YES

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m,q;
vector<vector<int>>g;
int compo_nu = 0;
vector<int>vis;    // vis[i] : stores compo_nu of ith node
vector<vector<int>>compo;    // comp[i] : stores nodes present in ith component 

void dfs(int node, int compo_nu){
    vis[node] = compo_nu;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,compo_nu);
        }
    }
}

void solve(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            compo_nu++;
            dfs(i,compo_nu);
        }
    }
    
    compo.resize(compo_nu+1);
    for(int i=1;i<=n;i++){
        compo[vis[i]].push_back(i);
    }

    while(q--) {
        int qu_nu;
        cin>>qu_nu;
        if(qu_nu == 1) {
            int c;
            cin >> c;
            cout<<compo[vis[c]].size()<<'\n';
        } else {
            int d, e;
            cin >> d >> e;
            if(vis[d] == vis[e]) cout<<"YES"<<'\n';
            else cout << "NO" <<'\n';
        }
    }   
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin >> n >> m >> q;
    g.resize(n+1);    // 1-based
    for(int i=0; i<m; i++){
        int a ,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.assign(n+1,0);
    
    solve();
    return 0;
}
