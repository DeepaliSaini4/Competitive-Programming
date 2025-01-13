/*
Q --> Reach from the starting to the end so that sum of elements on the path is maximum
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m;
vector<vector<char>>grid;
int dp[100100][100100];

int rec(int i,int j){//returns the number of paths ending at (i,j)

    //pruning
    if(i<0 || j<0)//no of ways to reach out of the index
    return 0;
    
    //base case
    if(i==0 && j==0)
    return 1;
    
    if(grid[i][j]=='#')
    return 0;
    
    //cache check
    if(dp[i][j]!=-1)
        return dp[i][j];
        
    //transition
    int ways = rec(i,j-1) + rec(i-1,j-1);
    
    //save and retun
    return dp[i][j] = ways;
}

void solver(){
    cin>>n>>m;
    grid.resize(n+1,vector<char>(m+1));
    memset(dp,-1,sizeof(dp));//resizing the dp

    //taking the grid input to be proceeded
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    //zero based  indexing
   cout<<"The number of ways to reach the ending cell are: "<<rec(n-1,m-1);//returns the number of paths ending at n-1 and m-1.
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
