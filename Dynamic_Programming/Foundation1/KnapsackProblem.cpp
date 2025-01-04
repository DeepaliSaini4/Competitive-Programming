#include <bits/stdc++.h>
using namespace std;
int n;
int w[3003];
int v[3003];
int W;

int dp[3003][3003];
int rec(int i,int x){
    //pruning
    //base case
    if(i==n){
        return 0;
    }
    //cache check
    if(dp[i][x]!=-1){
        return dp[i][x];
    }
    //transition
    int ans= rec(i+1,x);
    if(w[i]<=x){
        ans = max(ans,rec(i+1,x-w[i])+v[i]);
    }
    //save and return
    return dp[i][x] = ans;
}

void solver(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,W)<<"\n";
}

int main()
{ solver();
    return 0;
}