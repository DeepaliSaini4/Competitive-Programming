/*
Q--> Find the maximum sum path from (1,1) to (n,m) if only to down and to left moves allowed
*/
#include <bits/stdc++.h>
using namespace std;

int n;
int m;
int arr[1001][1001];
int dp[1001][1001];
bool done[1001][1001];//maintained since the computed sum value can be -1 as well

int rec(int r,int c){
    //pruning
    if(r<0 || c<0)
    {//not possible
        return -1e9;
    }
    //basecase
    if(r==0 && c==0){
        return arr[0][0];
    }
    
    //save and check
    if(done[r][c]){
        return dp[r][c];
    }
    //compute  
    int ans = max(rec(r-1,c)+arr[r][c],rec(r,c-1)+arr[r][c]);
    
    // save and return
    done[r][c] = 1;
    return dp[r][c] = ans;
    
}

void solver(){
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            done[i][j] = 0;
        }
    }
    cout<<rec(n-1,m-1)<<"\n";
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}