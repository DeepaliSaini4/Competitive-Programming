//Q- given a grid with S and F and walls. Find the min number of walls to be destroyed in order to reach F from S.
#include <bits/stdc++.h>
using namespace std;

# define F first
# define S second
const int INF = 100;
/*
 6 6 1
 S . # . . .
 . . # . . .
 # # # . # .
 . . . . # .
 # # # # . .
 F . . . . .
*/
int n, m, k;
vector<vector<char>> arr;
using state = pair<int , int >;
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
        int x = node.F + dx[k];
        int y = node.S + dy[k];
        if(is_valid(x,y)){
            neighs.push_back({x,y});
        }
    }
    return neighs;
}

vector<vector<int>> dis;

void bfs(state st_node){
    dis.assign(n,vector<int>(m,INF));
    
    deque<state> q;
    dis[st_node.F][st_node.S]= 0;
    q.push_front(st_node);
    
    while(!q.empty()){
        state node = q.front();
        q.pop_front();
        for(state v:neighbors(node)){
            int edge_w = 0;
            if(arr[v.F][v.S] == '#')edge_w =1;
            if(dis[v.F][v.S] >dis[node.F][node.S] + (edge_w)){
                dis[v.F][v.S] =dis[node.F][node.S] + (edge_w);
                //0-1 bfs
                if(edge_w == 0) q.push_front(v);
                else { q.push_back(v);}
                
            }
        }
    }
}
int main(){
    cin>> n>> m >>k;
    arr.resize(n);
    
    state st, en;
    
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
    bfs(st);
  for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          cout<<dis[i][j]<<'\t';
      }
      cout<<endl;
  }
  if(dis[en.F][en.S] == INF){
      cout<<"Finish is not reachable\n";
  }else{
      cout << dis[en.F][en.S] << endl;
  }
  
}
