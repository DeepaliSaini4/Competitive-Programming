//Rat in a maze
#include<bits/stdc++.h>
using namespace std;

int dc[4]={0,-1,1,0};
int dr[4]={1,0,0,-1};
char c[4] = {'d','l','r','u'};

void solver(vector<vector<int>>&m,vector<string>&ans, vector<vector<bool>>visited,int row,int col,string s){
    //base case
    if(col==m[0].size()-1 && row == m.size()-1){
        ans.push_back(s);
    }
    //choice
    for(int i=0;i<4;i++){
        int x = row + dr[i];
        int y = col + dc[i];
        if(x>=0 && y>=0 && y<m[0].size() && x<m.size() && m[x][y]==1 && visited[x][y]!=1){
            visited[x][y] = 1;
            s = s+ c[i];
            solver(m,ans,visited,x,y,s);
            visited[x][y] = 0;
            s.pop_back();
        }
    }
}

int main() {
  int n = 4;

   vector < vector < int >> m = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
   if(m[0][0]==0) cout<<"NO Path\n";
   vector<string> ans;
   vector<vector<bool>>visited(n,vector<bool>(n,false));
   string s = "";
   solver(m,ans,visited,0,0,s);
   for(auto it:ans){
       cout<<it<<" ";
   }
      return 0;
}
//tc = (number of choices for each step)^(total steps) 4^(m*n)
