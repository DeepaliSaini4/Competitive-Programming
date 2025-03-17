// find gcd of paths in tree
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int LOG = 20;

vector<int> neigh[MAXN], val(MAXN);
int par[MAXN][LOG], depth[MAXN], dp[MAXN][LOG];

void dfs(int node, int prev, int dep) {
    par[node][0] = prev;
    depth[node] = dep;
    dp[node][0] = val[node];

    for (int i = 1; i < LOG; i++) {
        if (par[node][i - 1] != -1) {
            par[node][i] = par[par[node][i - 1]][i - 1];
            dp[node][i] = gcd(dp[node][i - 1], dp[par[node][i - 1]][i - 1]);
        } else {
            par[node][i] = -1;
        }
    }

    for (auto v : neigh[node]) {
        if (v != prev) {
            dfs(v, node, dep + 1);
        }
    }
}

int pathgcd(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    
    int ans = 0;
    
    // Bring u to the same depth as v
    for (int i = LOG - 1; i >= 0; i--) {
        if ((depth[u] - depth[v]) & (1 << i)) {
            ans = gcd(ans, dp[u][i]);
            u = par[u][i];
        }
    }
    
    if (u == v) return gcd(ans, val[u]);
    
    // Move both u and v up together while maintaining GCD
    for (int i = LOG - 1; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            ans = gcd(ans, dp[u][i]);
            ans = gcd(ans, dp[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    
    return gcd(ans, val[u], val[v], val[par[u][0]]);
}

int main() {
    int n;
    cin >> n;

    // Input tree structure
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        neigh[u].push_back(v);
        neigh[v].push_back(u);
    }

    // Input node values
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    // Initialize LCA table
    memset(par, -1, sizeof(par));

    // Run DFS from root (assuming root is node 1)
    dfs(1, -1, 0);

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << pathgcd(u, v) << '\n';
    }

    return 0;
}
//tc =n(log^2)n --> nlognlog(val)
