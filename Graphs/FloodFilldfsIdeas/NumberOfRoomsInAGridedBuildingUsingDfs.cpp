/*
Description
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n × m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.

Input Format
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either ‘.’ (floor) or '#' (wall).

Output Format
Print one integer: the number of rooms.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1

5 8
########
#..#...#
####.#.#
#..#...#
########
Sample Output 1

3
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<char>>g;
vector<vector<bool>>vis;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int n,m;

bool check(int x,int y){
    if(x >= 0 &&  x <  n && y >= 0 && y < m) return 1;
    return 0;
}

void dfs(int x, int y ){
    vis[x][y] = 1;
    for(int i=0;i<4;i++){
        if(check(x+dx[i],y+dy[i]) && g[x+dx[i]][y+dy[i]] == '.'){
            if(!vis[x+dx[i]][y+dy[i]]){
                dfs(x+dx[i],y+dy[i]);
            }
        }
    }
}

void solver(){
    int ans = 0;
     for (int i=0;i<n;i++){
          for(int j=0;j<m;j++){
                if(!vis[i][j] && g[i][j]=='.'){
                dfs(i,j);
                ans++;
            }
         }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;

    g.resize(n+1,vector<char>(m+1));
    vis.assign(n+1,vector<bool>(m,0));
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>g[i][j];
        }
    }

    solver();

    return 0;
}
/*
T- DFS

D- a given cell is visited only when it:
unvisited
is a " . "
is a valid cell

*/