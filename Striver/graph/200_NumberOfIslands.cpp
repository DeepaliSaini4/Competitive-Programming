/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.


*/
class Solution {
public:
    bool isvalid(int x,int y,int r,int c){
        return(x>=0 && y>=0 && x<r && y<c);
    }
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    void dfs(vector<vector<char>>& grid,vector<vector<int>>&vis,int x,int y){
        vis[x][y] = 1;
        for(int i=0;i<4;i++){
            int newx = x+dx[i];
            int newy = y+dy[i];
            if(isvalid(newx,newy,grid.size(),grid[0].size())&& !vis[newx][newy] && grid[newx][newy]=='1'){
                dfs(grid,vis,newx,newy);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(grid,vis,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};
