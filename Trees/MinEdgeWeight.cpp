/*
Description
You are given a weighted tree of N nodes. D(u,v) is defined as the minimum weight of edge in the simple path from u to v.  Find the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v.

Input Format
The first line of input contains one integer T (1 ≤ T ≤ 105) — the number of test cases. Then T test cases follow.
The first line of each test case contains an integer N - the number of nodes in the tree (1 ≤ N ≤ 105).
The next N-1 line of each test case contains 3 space-separated integers u, v, w  denoting that there is an edge between node u and node v of weight w. (1 ≤ u,v ≤ N), (1 ≤ w ≤ 109 ).

It is guaranteed that the sum of N over all test cases does not exceed 106.

Output Format
For each test case print the summation of D(u,v) for all 1≤u≤N, 1≤v≤N, where u<v in a new line.
Sample Input 1
5
5
1 2 1
2 3 5
3 4 3
4 5 2
5
1 2 5
1 3 4
2 4 1
3 5 2
5
1 2 3
2 3 4
2 4 6
3 5 1
8
1 2 4
2 3 6
2 4 1
2 5 3
3 6 1
3 7 3
3 8 1
10
1 2 10
1 3 5
1 4 9
1 5 7
2 6 10
2 7 11
3 8 9
3 9 11
3 10 15

Sample Output 1
21
23
27
53
316
*/
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int par[100001];
    int size[100001];
    
    void init(int n) {
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            size[i] = 1;
        }
    }

    int find(int node) {
        if (par[node] == node)
            return node;
        else return par[node] = find(par[node]);
    }

    void merge(int nodex, int nodey) {
        int rootx = par[nodex];
        int rooty = par[nodey];

        if (size[rootx] < size[rooty])
            swap(rootx, rooty);
        par[rooty] = rootx;
        size[rootx] += size[rooty];
    }
};

int n;
vector<pair<int, pair<int, int>>> edges;

void solve () {
    cin >> n;
    edges.clear();
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, {a, b}});
    }
    sort(edges.begin(), edges.end());
    reverse(edges.begin(), edges.end());
    DSU dsu;
    dsu.init(n);
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        int parx = dsu.find(edges[i].second.first);
        int pary = dsu.find(edges[i].second.second);

        if (parx != pary) {
            ans += (edges[i].first * (dsu.size[parx] * 1LL * dsu.size[pary]));
            dsu.merge(parx, pary);
        }
    }
    cout << ans << endl;
}

int main() {
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
