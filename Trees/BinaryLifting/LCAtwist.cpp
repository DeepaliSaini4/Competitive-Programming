#include <bits/stdc++.h>
using namespace std;

#define int long long 

vector<vector<int>> g;
vector<int> depth;
vector<vector<int>> par;

void dfs(int node, int parent, int dep) {
    depth[node] = dep;
    par[node][0] = parent;
    
    for (int i = 1; i <= 20; i++) {
        if (par[node][i - 1] != -1) { 
            par[node][i] = par[par[node][i - 1]][i - 1];
        } else {
            par[node][i] = -1; 
        }
    }

    for (auto v : g[node]) {
        if (v != parent) {
            dfs(v, node, dep + 1);
        }
    }
}

int lca(int u, int v) { // Returns the LCA of u and v when the root is 1, O(logN)
    if (depth[u] < depth[v]) swap(u, v);

    // Bring u and v to the same level
    for (int i = 20; i >= 0; i--) {
        if ((depth[u] - depth[v]) & (1 << i)) { // Bitwise AND
            // If both u and v have different depths and the ith bit is set,
            // perform binary lifting on u
            u = par[u][i];
        }
    }

    if (u == v) return u;

    // Moving u and v up simultaneously until they are different
    for (int i = 19; i >= 0; i--) { 
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

void solver() {
    int n;
    cin >> n;

    g.assign(n + 1, vector<int>()); // 
    par.assign(n + 1, vector<int>(21, -1)); // 
    depth.assign(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, -1, 0); 

    int q;
    cin >> q;
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;

        // The middle LCA is the LCA that is not dominated by the other two LCAs,
        // meaning it remains the correct LCA when considering a different root perspective.
        int a = lca(x, y), b = lca(x, z), c = lca(y, z);
        if (b == a) cout << c << '\n'; // If LCA(x, z) is same as LCA(x, y), print LCA(y, z)
        else if (c == a) cout << b << '\n'; // If LCA(y, z) is same as LCA(x, y), print LCA(x, z)
        else cout << a << '\n'; // Otherwise, print LCA(x, y)
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--) solver();
    return 0;
}
//TC = O(NlogN)+O(QlogN)=O((N+Q)logN)
// preprocessing (dfs + binary lifting table construction) + each Query(bonary liftingto equalize depth+ find lca) + q querries 
