/*
Description
Given an array having 
n elements, the cost to move from 
i thelement to its adjacent element ( if exist ) at 
i+1 and 
i−1 is 
b, and the cost to move to other same valued index is 
a. Find min cost to reach every index from a given source index of the array.

Input Format
First-line contains 
n - size of the array and costs 
a and 
b..
Second line contains 
n elements of the array.
The third line contains a source index 
src.

Output Format
In a single line, print the min-cost to reach every index from a given source index 
src.

Constraints
1≤n≤2×10 
1≤a,b≤10 
1≤arr[i]≤100
1≤src≤n
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define pii pair<int, int>
#define F first
#define S second

int n, a, b;
map<int, vector<int>> mp;    // mp[i] : stores positions where value i is present
int src;
vector<vector<pii>> g;
vector<int> dis;
vector<int> vis;

void dijkstra(int sc_node) {
  priority_queue<pii> pq;    // {-distance, node}
  pq.push({-0, sc_node});
  dis[sc_node] = 0;

  while(!pq.empty()) {
    auto x = pq.top();
    pq.pop();
    
    if(vis[x.S] == 1) continue;
    vis[x.S] == 1;

    for(auto v:g[x.S]) {
      if(dis[v.F] > dis[x.S] + v.S) {
        dis[v.F] = dis[x.S] + v.S;
        pq.push({-dis[v.F], v.F});
      }
    }
  }
}

void solve() {
  // GRAPH FORMULATION
  int distinct_vals = mp.size();
  g.resize(n + distinct_vals + 1);   
  // Assign all edges of cost b
  for(int i=1; i<=n-1; i++) {
    g[i].push_back({i+1, b});
    g[i+1].push_back({i, b});
  }
  // Assign all edges of cost a
  int super_node = n+1;    // Start counting super node from n+1 (as 1 to n is already taken)
  for(auto v:mp) {
    for(auto u:v.S) {
      g[u].push_back({super_node, a});
      g[super_node].push_back({u, 0});
    }
    super_node++;
  }

  dis.resize(n + distinct_vals + 1, 1e18);
  vis.resize(n + distinct_vals + 1, 0);
  dijkstra(src);

  for(int i=1; i<=n; i++) cout << dis[i] << " ";
  cout << '\n';
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n >> a >> b;
  for(int i=1; i<=n; i++) {
    int x;
    cin >> x;
    mp[x].push_back(i);
  }
  cin >> src;

  solve();
  return 0;
}