/*
Description
You and some monsters are in a matrix. When taking a step to some direction in the matrix, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
Your task is to find out if your goal is possible, and if it is, print the shortest length of the path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

Input Format
The first input line has two integers n and m: the height and width of the matrix.
After this, there are n lines of m characters describing the matrix. Each character is ‘.’ (floor), ‘#’ (wall), ‘A’ (start), or ‘M’ (monster). There is exactly one ‘A’ in the input.

Output Format
First, print "YES" if your goal is possible, and "NO" otherwise.
If your goal is possible, also print the length of the shortest path that you'll follow.

Constraints
1 ≤ n, m ≤ 1000

Sample Input 1
5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

Sample Output 1
YES
5

Sample Input 2
3 3
###
#A#
#M.

Sample Output 2
NO

Sample Input 3
1 3
##A

Sample Output 3
YES
0
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

using state = pair<int,int>;

int n,m;
vector<vector<char>>g;
vector<state>mons;
vector<state>boun;
vector<vector<int>>min_dismon;
vector<vector<int>>min_dispsn;
state st;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

bool check(int x,int y){
    return (x>=0 && y>=0 && x<n && y<m && g[x][y]=='.');
}

void multibfs(){
    queue <state> qu;
    for(auto it:mons){
        qu.push(it);
        min_dismon[it.F][it.S] = 0;
    }
     while(!qu.empty()){
        int x = qu.front().F;
        int y = qu.front().S;
        qu.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(check(nx,ny)){
                if(min_dismon[nx][ny]>min_dismon[x][y]+1){
                    qu.push({nx,ny});
                    min_dismon[nx][ny] = min_dismon[x][y]+1;
                }
            }
        }
    }    
}

void bfs(state node){
    queue <state> qu2;
    qu2.push(node);
    min_dispsn[node.F][node.S] = 0;
    while(!qu2.empty()){
        int x = qu2.front().F;
        int y = qu2.front().S;
        qu2.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(check(nx,ny)){
                if(min_dispsn[nx][ny]>min_dispsn[x][y]+1){
                    qu2.push({nx,ny});
                    min_dispsn[nx][ny] = min_dispsn[x][y]+1;
                }
            }
        }
    }
}

void solver(){

    multibfs();
    bfs(st);
    for(auto v:boun){
        if(min_dismon[v.F][v.S] > min_dispsn[v.F][v.S]){
            cout<<"YES"<<'\n'<<min_dispsn[v.F][v.S];
            return;
        }
    }
    cout<<"NO"<<'\n';
}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    char c;
    g.resize(n+1,vector<char>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>c;
            g[i][j]=c;
            if(c=='A'){
                st={i,j};
                 if(i==0 || j==0 || i==n-1 || j==m-1)
                  boun.push_back({i,j});
            }
            else if(c=='M'){
               mons.push_back({i,j});
            }
            else if((i==0 || j==0 || i==n-1 || j==m-1) && c=='.'){
                boun.push_back({i,j});
            }
        }
    }

    min_dismon.assign(n+1,vector<int>(m+1,1e9));
    min_dispsn.assign(n+1,vector<int>(m+1,1e9));
   
   solver();
    
}
/*
C : Multi source BFS

F : Who is near to the ending/boundary cells? the person or the monster.

For the given boundary cells who is nearer? the monster or the person?

T :

D :if the starting point of the person is a boundary point it should be considered as well. not the monsters one though.

*/