#include<bits/stdc++.h>
using namespace std;

int n;
int dp[100100];

int rec(int level){//ret-->number of way to N if we are at stair level.
    //level -->stair i am at
    
    //pruning code
    if(level>n)
    return 0;
    //base case
    if(level==n){
        return 1;
    }
    
    if(dp[level]!=-1){
        return dp[level];
    }
    int ans = 0;
    //loop over choices
    for(int step=1;step<=3;step++){
        if(level+step<=n){
            //check -> is valid choice
            
            int ways = rec(level + step); //move
            ans+=ways;
        }
    }
    dp[level]=ans;
    return ans;//for this level
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1);
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    int t=1;
    while(t--)
    solve();
    return 0;
}