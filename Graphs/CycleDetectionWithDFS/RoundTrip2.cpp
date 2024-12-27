/*
Description
Zenithland has 

n cities and 

m flight connections. Your task is to design a round trip that begins in a city, goes through one or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input Format
First line contains 

T - Number of test cases.
First input line of each test case has two integers 

n and 

m: the number of cities and flights. The cities are numbered 

1,2,…,n.
Then, for each test case, there are 

m lines describing the flights. Each line has two integers 
a and 

b: there is a flight connection from city 

a to city 
b. All connections are one-way flights from a city to another city.

Output Format
For each test case, Print "Yes" if such round trip exists, otherwise print "No" in a new line.

Constraints

1≤T≤10

1≤n≤10 

1≤m≤2⋅10 

1≤a,b≤n

Sample Input 1
1
4 5
1 3
2 1
2 4
3 2
3 4

Sample Output 1
Yes
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n, m;
vector<vector<int>> g;
vector<int> indeg;
int vis_cnt = 0;

void bfs_kahn() {
    // Initialize queue with all nodes having in-degree 0
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }

    // Perform Kahn's algorithm
    while(!q.empty()) {
        int x = q.front();
        vis_cnt++;
        q.pop();

        for(auto v:g[x]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                q.push(v);
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    g.resize(n+1);    // 1-based
    indeg.assign(n+1, 0);
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        indeg[b]++;
    }

    bfs_kahn();

    if(vis_cnt < n) cout << "Yes\n";
    else cout << "No\n";

    g.clear();
    indeg.clear();
    vis_cnt=0;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int _t; cin >> _t; while(_t--) solve();
    return 0;
}