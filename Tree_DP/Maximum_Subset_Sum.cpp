/*
Q->for given a tree of  n nodes ith node has a value a[i]find a subset 
of nodes st no two nodes are connected by an edge and total value of subset 
is maximum. print the maximum value as well.
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int N = 100010;
vector<int> graph[N];
int dp[N][2];
int A[N];

void dfs(int cur, int prev) {
    dp[cur][0] = 0;
    dp[cur][1] = A[cur];
    for (int child : graph[cur]) {
        if (child == prev) continue;
        
        dfs(child, cur);
        
        // dp[child][0] and dp[child][1] are computed
        dp[cur][1] += dp[child][0];
        dp[cur][0] += max(dp[child][0], dp[child][1]);
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }
    
    dfs(1, -1);
    cout << max(dp[1][0], dp[1][1]) << '\n';
}
