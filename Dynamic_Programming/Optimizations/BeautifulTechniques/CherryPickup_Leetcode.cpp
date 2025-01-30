/*
Q -> You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.
0 means the cell is empty, so you can pass through,
1 means the cell contains a cherry that you can pick up and pass through, or
-1 means the cell contains a thorn that blocks your way.
Return the maximum number of cherries you can collect by following the rules below:
Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
*/
class Solution {
public:
    int n;
    int dx[2]={0,1};
    int dy[2]={1,0};
    int dp[51][51][51];

    bool check(int a ,int b,vector<vector<int>>&grid){
        return (a>=0 && a<n && b>=0 && b<n && grid[a][b]!=-1);
    }
    int rec(int i,int j,int a,vector<vector<int>>&grid){//returns the maximum number of cherries picked up till (i,j)&(a,b) provided that there exists a vaild path from (i,j) to (n-1,n-1)
        //pruning
        int b = (i + j) - a;


        //base case
        if(i==n-1 && j==n-1){
            return grid[i][j];//other one also eaches the ned at the same time
        }
        //cache check
        if(dp[i][j][a]!=-1){
            return dp[i][j][a];
        }
        //transition
        int initial_cherry = grid[a][b] + grid[i][j];
        if(i==a && j==b){
            initial_cherry = grid[a][b];//avoiding double counting
        }
        int cherry = INT_MIN;
        for(int k1=0;k1<2;k1++){
            for(int k2=0;k2<2;k2++){
                int ni = i + dx[k1];
                int nj = j + dy[k1];
                int na = a + dx[k2];
                int nb = b + dy[k2];
                if(check(ni,nj,grid) && check(na,nb,grid)){//only give call for the path if the path is valid
                    int next = rec(ni,nj,na,grid);
                    if(next!=INT_MIN)
                    cherry = max(cherry ,next + initial_cherry);
                }
            }
        }
        //save and return 
        return dp[i][j][a] = cherry;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp,-1,sizeof(dp));
        if(grid[0][0]==-1 || grid[n-1][n-1]==-1) return 0;//edge case
        int ans = rec(0,0,0,grid);
        if(ans==INT_MIN)
            ans = 0;
        return ans;
    }
};
