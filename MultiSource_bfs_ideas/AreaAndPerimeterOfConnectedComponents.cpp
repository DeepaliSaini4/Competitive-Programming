/*
Description
You have been given a grid of size N x N. Each cell is either empty (.) or occupied (#). Size of each cell is 1 x 1. In the connected component, you can reach any cell from every other cell in the component by repeatedly stepping to adjacent cells in the north, south, east, and west directions. 
Your task is to find the area and perimeter of the connected component having the largest area. The area of a connected component is just the number of '#' characters that are part of it. If multiple connected components tie for the largest area, find the smallest perimeter among them.

Input Format
The first line of input contains N, and the next N lines describe the grid. At least one '#' character will be present.

Output Format
Please output one line containing two space-separated integers, the first being the area of the largest connected component, and the second being its perimeter. If multiple connected components tie for the largest area, print the one which has the smallest perimeter among them.

Constraints
1 ≤ N ≤ 1000

Sample Input 1
6
##....
....#.
.#..#.
.#####
...###
....##

Sample Output 1
13 22
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second

using state = pair<int,int>;

int n;  
vector<vector<char>>g;  //stores input grid
vector<vector<int>>dis; //stores the min path distance to reach any {i,j} starting from {0,0}
vector<vector<state>>comp; //stores the call nodes belonging to a given component
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int compo_no=0;

bool check(int x,int y){
    return (x>=0 && x<n && y>=0 && y<n);
}

void bfs(state node,int compo_no){
    queue <state> qu;
    qu.push(node);
    dis[node.F][node.S] = 0;
    while(!qu.empty()){
        int x = qu.front().F;
        int y = qu.front().S;
        comp[compo_no].push_back({x,y});
        qu.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(check(nx,ny) && g[nx][ny]!='.'){
                if(dis[nx][ny]>dis[x][y]+1){
                    qu.push({nx,ny});
                    dis[nx][ny] = dis[x][y] + 1;
                }
            }
        }
    }
}

void solver(){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(g[i][j]!='.' && dis[i][j] == 1e9){
                 compo_no++;
                bfs({i,j},compo_no);
            }
        }
    }
    priority_queue<state>pq;//{area, -perimeter}
    for(int i=1;i<=compo_no;i++){
        int area = comp[i].size();
        int peri = 0;

        for(int j=0;j<area;j++){
            int x = comp[i][j].F;
            int y = comp[i][j].S;
            // boundary edges
            peri+=((x==0) + (x==n-1)+ (y==0) + (y==n-1));

            for(int k=0;k<4;k++){
                int nx = x+dx[k];
                int ny = y+dy[k];
                if(check(nx,ny) && g[nx][ny]=='.'){
                    peri++;
                }
            }
        }
        pq.push({area,-peri});
    }
    cout<<pq.top().F<<" "<<-1*(pq.top().S)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    
    g.resize(n);
    for(int i=0;i<n;i++){
        g[i].resize(n);
        for(int j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    
    dis.assign(n,vector<int>(n,1e9));
    comp.resize(n*n+1);

    solver();

    return 0;

}