/*
You are given a tree consisting of n nodes. The diameter of a tree is the maximum distance between two nodes. Your task is to count the number of different diameters of
the tree.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n.
Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the count of diameters of the tree.

Constraints
1 ≤ n ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5
1 2
1 3
3 4
3 5

Sample Output 1
2
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

int n;  
vector<vector<int>> graph;  
int depth_[200010];  
int parent[200010];  

// Standard DFS to compute depths and parent of each node
void dfs(int node, int par, int depth) {
    parent[node] = par;
    depth_[node] = depth;
    for (auto it : graph[node]) {
        if (it != par) {
            dfs(it, node, depth + 1);
        }
    } 
}

// Count nodes at the required depth
int cnt(int node, int par, int curd, int reqd) {
    if (curd == reqd) return 1;
    int totc = 0;
    for (auto it : graph[node]) {
        if (it != par) {
            totc += cnt(it, node, curd + 1, reqd);
        }
    }
    return totc;
}

void solver() {
    int x = 1;
    dfs(x, 0, 0); 

    // Finding the farthest node y_max from node 1
    int nmax = 1;
    for (int i = 2; i <= n; i++) {
        if (depth_[i] > depth_[nmax]) {
            nmax = i;
        }
    }

    // Running DFS from this farthest node
    dfs(nmax, 0, 0);  

    // Finding the farthest node from nmax, which gives the tree's diameter
    int z_max = nmax;
    for (int i = 1; i <= n; i++) {
        if (depth_[i] > depth_[z_max]) {
            z_max = i;
        }
    }

    int dia = depth_[z_max];  // Diameter of the tree

    if (dia <= 1) {  
        cout << 1 << '\n';  
        return;  
    }  

    // Case when diameter is even
    if (dia % 2 == 0) {  
        int dist = dia / 2;
        while (dist--) {
            z_max = parent[z_max];  // Move halfway up the longest path
        }

        // Counting the number of nodes at required depth
        vector<int> res;
        for (auto it : graph[z_max]) {
            res.push_back(cnt(it, z_max, 0, dia / 2 - 1));
        }

        // Calculating the number of valid node pairs
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < res.size(); i++) {
            ans += (sum * res[i]);
            sum += res[i];
        }

        cout << ans << '\n';
        return;
    } else {  
        // Case when diameter is odd
        int c1 = z_max;
        int dist = (dia - 1) / 2;
        while (dist--) {
            c1 = parent[c1];  // Move up the longest path
        }
        int c2 = parent[c1];  // The other median node

        // Counting nodes at the required depth from c1
        memset(depth_, 0, sizeof(depth_));
        //Passing center2 as the parent of center1 (and vice versa) ensures DFS explores only one side at a time, preventing backtracking and correctly counting nodes in each half for valid diameter pairs.
        dfs(c1, c2, 0);  

        int cnt1 = 0;
        for (int i = 1; i <= n; i++) {
            if (depth_[i] == (dia / 2)) cnt1++;
        }

        // Counting nodes at the required depth from c2
        memset(depth_, 0, sizeof(depth_));
        dfs(c2, c1, 0);  

        int cnt2 = 0;
        for (int i = 1; i <= n; i++) {
            if (depth_[i] == (dia / 2)) cnt2++;
        }

        cout << cnt1 * cnt2 << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    graph.assign(n + 1, vector<int>());

    // Reading edges and building the tree
    for (int i = 1; i < n; i++) {  
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    
    solver();

    return 0;
}
