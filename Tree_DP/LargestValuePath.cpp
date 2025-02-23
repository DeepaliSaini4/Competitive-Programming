/*
Q-> Given a tree find the largest value path.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

const int inf = 1e9;
const int N = 100010;
vector<int> graph[N];
int maxpath[N];  // Stores the maximum path sum starting from this node
int A[N];
int ans = -inf;  // Global max sum

void dfs(int cur, int prev) {
    vector<int> allchildpaths;

    // Traverse children
    for (int child : graph[cur]) {
        if (child == prev) continue;  // Avoid revisiting parent
        dfs(child, cur);
        allchildpaths.push_back(maxpath[child]);  // Store the max sum from child
    }

    // Sort to get the two largest child paths
    sort(allchildpaths.begin(), allchildpaths.end());

    // **Case 1: Leaf Node (No children)**
    if (allchildpaths.empty()) {  
        ans = max(ans, A[cur]);  // The max sum is just the node's value
        maxpath[cur] = A[cur];
    }
    // **Case 2: Node with One Child**
    else if (allchildpaths.size() == 1) {  
        maxpath[cur] = max(A[cur], allchildpaths[0] + A[cur]);  // Either take only the node or extend child path
        ans = max(ans, maxpath[cur]);
    }
    // **Case 3: Node with Two or More Children**
    else {  
        int m = (int)allchildpaths.size();
        ans = max(ans, A[cur] + allchildpaths[m - 1] + allchildpaths[m - 2]);  // Best two child paths + node value
        maxpath[cur] = max(A[cur], allchildpaths[m - 1] + A[cur]);  // Best single path from this node
        ans = max(ans, maxpath[cur]);  // Update global answer
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
    cout << ans << '\n';  // Print the max path sum
}
