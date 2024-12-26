/*
Description
You have a 2-D array of size N x M. Consider connected 0s (which share a common edge) as one single component and 1s as walls. Replace 0s with the size of the connected component but if the size of the component is one, then leave it with 0.

Input Format
The first line contains a single integer t, the number of test cases.
For each test case, the first line contains two integers N and M and then there are N lines containing M 0s and 1s, representing a N x M binary matrix.

Output Format
For each test case, print the final matrix after replacing all the 0s accordingly.

Constraints
1 ≤ Sum of (N x M) over all test cases ≤ 2 x 105
0 ≤ Ai ≤ 1

Sample Input 1

2
2 2
0 1
1 0
6 5
1 0 0 1 0
0 1 0 0 0
0 0 1 1 0
0 1 1 0 1
1 1 1 1 1
0 1 0 0 0
Sample Output 1

0 1 
1 0 
1 7 7 1 7
4 1 7 7 7
4 4 1 1 7
4 1 1 0 1
1 1 1 1 1
0 1 3 3 3
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>> g, vis;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m;

// Check if a cell is within bounds
bool check(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m);
}

// DFS to find the size of a connected component
void dfs(int i, int j, int &compo_sz, vector<pair<int, int>> &cells) {
    vis[i][j] = 1;
    compo_sz++;
    cells.push_back({i, j});

    for (int k = 0; k < 4; k++) {
        int ni = i + dx[k], nj = j + dy[k];
        if (check(ni, nj) && !vis[ni][nj] && g[ni][nj] == 0) {
            dfs(ni, nj, compo_sz, cells);
        }
    }
}

void solver() {
    cin >> n >> m;
    g.assign(n, vector<int>(m));
    vis.assign(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!vis[i][j] && g[i][j] == 0) {
                int compo_sz = 0;
                vector<pair<int, int>> cells; // Store cells in the current component
                dfs(i, j, compo_sz, cells);

                // Update component size in the grid
                for (auto &[x, y] : cells) {
                    g[x][y] = (compo_sz > 1 ? compo_sz : 0);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << g[i][j] << " ";
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solver();
    }

    return 0;
}