/*Description
Abhishek loves Snakes and Ladders game, he can always roll the die to whatever number he want between 
1 to 
6. Help him to find the least number of dice rolls to reach the destination i.e the 

100 
th
  cell from the 
1 
st
  cell.

Rules :-

The game is played with a cubic die of 
6 faces numbered 
1 to 
6.

Starting from square 
1, land on square 
100 with the exact roll of the die. If moving the number rolled would place the player beyond square 
100, no move is made.

If a player lands at the base of a ladder, the player must climb the ladder. Ladders go up only.

If a player lands at the mouth of a snake, the player must go down the snake and come out through the tail. Snakes go down only.

Input Format
The first line contains the number of tests, 
t.

For each test case:

The first line contains 
n, the number of ladders.

Each of the next 
n lines contains two space-separated integers, the start, and end of a ladder.

The next line contains the integer 
m, the number of snakes.

Each of the next 
m lines contains two space-separated integers, the start, and end of a snake.

Output Format
For each of the 
t test cases, print the least number of rolls to move from start to finish on a separate line. If there is no solution, print 
−1.

Constraints

1≤t≤10

1≤n,m≤15


The board is always 
10×10 with squares numbered 
1 to 
100 .
Neither square 
1 nor square 
100 will be the starting point of a ladder or snake.
A square will have at most one endpoint from either a snake or a ladder.
input:
2
3
32 62
42 68
12 98
7
95 13
97 25
93 37
79 27
75 19
49 47
67 17
4
8 52
6 80
26 42
2 72
9
51 19
39 11
37 29
81 3
59 5
79 23
53 7
43 33
77 21 

Sample Output 1
3
5
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>

int dis[101];
int go_immediately[101];
vector<int> vis;

bool check(int node) {
    return (node > 0 && node <= 100);
}

void bfs(int node) {
    vis.assign(101, 0);
    queue<int> q;
    q.push(node);
    dis[node] = 0;
    vis[node] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        // Try to go to all possible neighbors
        for (int i = 1; i <= 6; i++) { // Roll dice from 1 to 6
            int next = x + i;
            if (check(next)) {
                int nx = go_immediately[next]; // Use ladder/snake if exists
                if (!vis[nx]) {
                    q.push(nx);
                    vis[nx] = 1;
                    dis[nx] = dis[x] + 1;
                }
            }
        }
    }

    if (!vis[100])
        cout << -1 << '\n';
    else
        cout << dis[100] << '\n';
}

void solver() {
    int n;
    cin >> n;

    // Initialize go_immediately for all vertices
    for (int i = 1; i <= 100; i++) {
        go_immediately[i] = i;
    }

    // Input ladders/snakes
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        go_immediately[a] = b;
    }

    int m;
    cin >> m;

    // Input additional connections (if any)
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        go_immediately[u] = v;
    }

    // Reset distances
    fill(dis, dis + 101, LLONG_MAX);

    // Solve using BFS
    bfs(1);
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
