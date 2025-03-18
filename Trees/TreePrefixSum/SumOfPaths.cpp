// Q- find the sum of path of Q different simple paths as querries.
#include <bits/stdc++.h>
using namespace std;

#define int long long 

vector<vector<pair<int, int>>> g; 
vector<vector<int>> par;
vector<int> dep; 
vector<int> prefix; 


void dfs(int node, int depth, int parent, int val) {
    dep[node] = depth;
    par[node][0] = parent;
    prefix[node] = val + (parent == -1 ? 0 : prefix[parent]); 

    for (int i = 1; i <= 19; i++) { 
        if (par[node][i - 1] != -1) {
            par[node][i] = par[par[node][i - 1]][i - 1];
        } else {
            par[node][i] = -1; 
        }
    }

    for (auto v : g[node]) {
        if (v.first != parent) {
            dfs(v.first, depth + 1, node, v.second);
        }
    }
}

int getlca(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v); 

    for (int i = 19; i >= 0; i--) {
        if ((dep[u] - dep[v]) & (1 << i)) {
            u = par[u][i];
        }
    }

    if (u == v) return u; 

    for (int i = 19; i >= 0; i--) {
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

int getSum(int u, int v) {
    return prefix[u] + prefix[v] - 2 * prefix[getlca(u, v)];
}

void solver() {
    int n;
    cin >> n;

    par.assign(n + 1, vector<int>(20, -1));
    dep.assign(n + 1, 0);
    prefix.assign(n + 1, 0);

    g.assign(n + 1, vector<pair<int, int>>());

    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    dfs(1, 0, -1, 0); 

    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << getSum(u, v) << "\n";
    }

    par.clear();
    dep.clear();
    prefix.clear();
    g.clear();
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
/*O(T (N log N + Q log N)).
The time complexity is O(N log N) for preprocessing (DFS + Binary Lifting) and 
O(log N) per query, making the overall complexity O(T (N log N + Q log N)) for 
T test cases and Q queries per test case.
*/
