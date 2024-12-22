//Q--> Finding the length of the shortest path from S to F if can destroy K walls.
#include <bits/stdc++.h>
using namespace std;

# define F first
# define S second
const int INF = 100;
/*
 6 6 1
 S . # . . .
 . . # . . .
 # . # . # .
 . . . . # .
 # # # # . .
 F . . . . .
*/

int n, m, k;
vector<vector<char>> arr;
using state = pair<pair<int , int > , int>;
bool is_valid(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m){
        return 1;
    }
    return 0;
}

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
// int dx[] = {2,1,-1,-2,-2,-2,1,2};
// int dy[] = {-1,-2,-2,-1,1,2,2,1};

vector<state> neighbors(state node){
    vector<state> neighs;
    for(int k=0;k<4;k++){
        int x = node.F.F + dx[k];
        int y = node.F.S + dy[k];
        if(is_valid(x,y)){
            int z = node.S;
            if(arr[x][y] == '#') z+=1;// going to the next plane on encountering a wall
            if(z>k) continue;//not a valid neighbor
            neighs.push_back({{x,y},z});
        }
    }
    return neighs;
}

vector<vector<vector<int>>> dis;

void bfs(state st_node){
    dis.assign(n,vector<vector<int>>(m,vector<int>(k+1,INF)));
    
    queue<state> q;
    dis[st_node.F.F][st_node.F.S][st_node.S] = 0;
    q.push(st_node);
    
    while(!q.empty()){
        state node = q.front();
        q.pop();
        for(state v:neighbors(node)){
            if(dis[v.F.F][v.F.S][v.S] == INF){
                dis[v.F.F][v.F.S][v.S] = dis[node.F.F][node.F.S][node.S]+1;
                q.push(v);
            }
        }
    }
}

int main(){

    cin>> n>> m>> k;
    arr.resize(n);
    
    pair<int,int> st, en;
    
    for(int i=0;i<n;i++){
        arr[i].resize(m);
        for(int j=0;j<m;j++){
            cin>> arr[i][j];
            if(arr[i][j] == 'S'){
                st = {i,j};
            }
            else if (arr[i][j] == 'F'){
            en = {i,j};
            }
        }
    }

    bfs({st,0});
    int ans = INF;
    for(int bomb=0;bomb<=k;bomb++){
        ans = min(ans, dis[en.F][en.S][bomb]);
    }
    cout << ans << endl;
}






