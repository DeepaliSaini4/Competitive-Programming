#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<int>x;
int dp[1001][1001];

int rec(int l,int r){
    //pruning
    //base case
    if(l+1==r){
        return 0;
    }
    //cache check
    if(dp[l][r]!=-1) return dp[l][r];
    //compute
    int ans = 1e9;
    for(int p=l+1;p<=r-1;p++){
        ans = min(ans,x[r]-x[l]+rec(l,p)+rec(p,r));
    }
    //return and save
    return dp[l][r] = ans;
}

void solver(){
    cin>>n;
    x.resize(n+1);
    for(int i=1;i<=n;i++){
      cin>>x[i];
    }
    x[0] = 0;
    memset(dp,-1,sizeof(dp));

    cout<<rec(0,n)<<'\n';//returns the min cost to cut the rod from the length 0 to n.
    
    
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}