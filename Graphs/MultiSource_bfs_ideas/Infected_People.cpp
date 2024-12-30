/*
Description
Your city is having people infected with a virus. The city in which you live is represented as a grid consisting of n rows and m columns. Cells containing 2 are the cells where the people infected with the virus are present and the cells having 1 are the cells having people not yet infected with the virus. There are certain empty cells which are represented by 0. The infected people in a unit time can infect all their adjacent cells, i.e, if they are present at cell [i, j] they can infect cells [i-1, j], [i+1, j], [i, j-1] and [i, j+1]. The virus cannot pass through empty cells. Your task is to print the minimum time in which all the people are infected with the virus. If the virus cannot infect everyone, print -1.

Input Format
The first line contains two integers n and m  — the number of rows and columns, respectively.
The following n lines contain m integers each, the j-th element in the i-th line is the number written in the j-th cell of the i-th row.

Output Format
Print the minimum time in which everyone can be infected or -1 if everyone cannot be infected.

Constraints
1 <= n <= 1000
1 <= m <= 1000

Sample Input 1
3 3
0 1 2
0 1 2
1 1 2
Sample Output 1
2
Sample Input 2
3 3
0 1 2
0 1 2
1 0 2
Sample Output 2
-1
*/
#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define int long long

using state = pair<int,int>;
int n,m;
vector<state>inf;
vector<state>pers;
vector<vector<int>>grid;
vector<vector<int>>min_dis;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
int max_dis =0;

bool check(int x,int y){
    return(x>=0 && y>=0 && x<n && y<m && grid[x][y]!=0);
}
void multibfs(){
    queue<state> qu;
    for(auto it:inf){
        qu.push(it);
        min_dis[it.F][it.S] = 0;
    }
    while(!qu.empty()){
        int x = qu.front().F;
        int y = qu.front().S;
        grid[x][y] =2;
        qu.pop();
        for(int k=0;k<4;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(check(nx,ny)){
                 if(min_dis[nx][ny]>min_dis[x][y]+1){
                    qu.push({nx,ny});
                    min_dis[nx][ny] = min_dis[x][y]+1;
                }
                
            }

        }
       
    }

}

void solver(){
    multibfs();
    for(auto it:pers){
        max_dis=max(max_dis,min_dis[it.F][it.S]);
    }
    if(max_dis==1e9) cout<<-1<<'\n';
    else cout<<max_dis<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>> n >> m;
    int val;
    grid.resize(n+1,vector<int>(m+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> val;
            grid[i][j] = val;
            if(val == 1){
                pers.push_back({i,j});
            }
            else if(val == 2){
                inf.push_back({i,j});
            }
        }
    }
    min_dis.assign(n+1,vector<int>(m+1,1e9));

    solver();

    return 0;
}