/*
Description
Monkey D. Luffy, on his journey of becoming the "King of Pirates" and to conquer the "One Piece", wants to travel across the Grand Line. Grand Line is a mysterious sea, and is in the shape of a 
N∗M grid 
S with each cell denoting the wind direction. The sign of 
S[i][j] can be:
1 which means wind in the cell flows to the right. (i.e from 
S[i][j] to 
S[i][j+1])
2 which means wind in the cell flows to the left. (i.e from 
S[i][j] to 
S[i][j−1])
3 which means wind in the cell flows downwards. (i.e from 
S[i][j] to 
S[i+1][j])
4 which means wind in the cell flows upwards. (i.e from 
S[i][j] to 
S[i−1][j])
Notice that there could be some signs on the cells of the grid 

S that point outside the Grand Line sea grid.

Luffy's ship "Merry" can only sail along the wind direction and can't go outside the Grand Line sea grid 

S at any point.
Luffy can also modify the wind's direction on a cell with 

cost=1. ( can modify the sign on a cell one time only )
Find the minimum cost to make Luffy's Voyage from the top left corner of the Grand line i.e 

S[1][1] to its bottom right corner i.e 

S[N][M] possible.

Input Format
Input is given from Standard Input in the following format:
Input is given from Standard Input in the following format:
N M and a matrix of Si
 

Output Format
Print the answer.

Constraints
2≤N,M≤1000
N and M are integers.
1 ≤ 
S
i
,
j
S 
i,j
​
  ≤ 4.

Sample Input 1

4 4
1 1 1 1
2 2 2 2
1 1 1 1
2 2 2 2 

Sample Output 1

3
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define F first 
#define S second

using state = pair<int, int>;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> dis;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool is_valid(int x, int y) {
   return (x>=0 && y>=0 && x<n && y<n);
}

void bfs_01(state sc_node) {
    deque<state> dq;
    dq.push_back(sc_node);
    dis[sc_node.F][sc_node.S] = 0;

    while(!dq.empty()) {
        int x = dq.front().F, y = dq.front().S;
        dq.pop_front();

        for(int k=0; k<4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(is_valid(nx, ny)) {
                int wt = 1;
                if(arr[x][y] == 1 && k == 0) wt = 0; 
                else if(arr[x][y] == 2 && k == 1) wt = 0;
                else if(arr[x][y] == 3 && k == 2) wt = 0;
                else if(arr[x][y] == 4 && k == 3) wt = 0;


                if(dis[nx][ny] > dis[x][y] + wt) {
                    dis[nx][ny] = dis[x][y] + wt;
                    if(wt == 0) {
                        dq.push_front({nx, ny});
                    } else {
                        dq.push_back({nx, ny});
                    }
                }
            }
        }
    }
}

void solve() {
    bfs_01({1, 1});

    cout << dis[n][m] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m; 
    arr.resize(n+1);    // 1-based
    for(int i=1; i<=n; i++) {
        arr[i].resize(m+1);
        for(int j=1; j<=m; j++) {
            cin >> arr[i][j];
        }
    }
    dis.assign(n+1, vector<int> (m+1, 1e9));

    solve();
    return 0;
}