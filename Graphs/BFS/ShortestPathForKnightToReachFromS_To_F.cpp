/*
You are given an N×N chessboard and a knight with starting position (Sx,Sy). You are given a final position 
(Fx,Fy). You have to find the minimum number of moves required to reach the final position.

Complete the function:

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy);
Input Format
The first line contains a single integer T - the number of test cases.
The first line of each test case contains five integers N Sx Sy Fx Fy - the size of the board, initial position and final position.

Output Format
For every test case print the minimum number of moves required. If it is not possible print -1.

onstraints
1 ≤ T ≤ 20
1 ≤ N ≤ 1000
1 ≤ Sx, Sy, Fx, Fy ≤ N

Sample Input 1
3
6 4 5 1 1
6 3 3 6 6
6 6 1 1 6

Sample Output 1
3
2
4
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long

using ii = pair<int,int>;

bool check(int x,int y,int n){
    return ( x>0 && x<=n && y>0 && y<=n);
}

int KnightWalk(int N, int Sx, int Sy, int Fx, int Fy)
{ 
	int dx[] = {2, 2, -2, -2, 1, -1, 1, -1};
    int dy[] = {1, -1, 1, -1, 2, 2, -2, -2};

    vector<vector<int>>dis(N+1,vector<int>(N+1,1e9));

    queue<ii>qu;
    qu.push({Sx,Sy});
    dis[Sx][Sy]=0;

    while(!qu.empty()){

        int x = qu.front().first;
        int y = qu.front().second;
        qu.pop();

        for(int k=0; k<8; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if(check(nx, ny, N)) {
                if(dis[nx][ny] > dis[x][y] + 1) {
                    qu.push({nx, ny});
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
    }
  return dis[Fx][Fy]!=1e9? dis[Fx][Fy]:-1;
}


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case;
	cin >> test_case;

	while (test_case--)
	{
		int N, Sx, Sy, Fx, Fy;
		cin >> N >> Sx >> Sy >> Fx >> Fy;

		cout << KnightWalk(N, Sx, Sy, Fx, Fy) << "\n";
	}
    return 0;
}
/*
Debug: Take care on indexing
for one based take size of distance grid n+1 x n+1, and in limits check for equal and less than n.
for one based take size of distance grid n x n, and in limits check for equal and more than zero and less than n. Also convert initial given coordinates to zero based by decrementing them.
*/