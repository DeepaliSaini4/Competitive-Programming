/*
Q -> There are n types of coin denominations:
  x1, x2, x3, x4, ........... xn
  can you make sum of M with these denominations.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

void solver(){
    int n,m;
    cin>>n>>m;
    int x[n];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int dp[n+1][m+1];
    for(int l=n;l>=0;l--){
        for(int s=0;s<=m;s++){
            //compute for (l,s)
            if(l==n){
                if(s==0) dp[l][s] = 1;
                else dp[l][s] = 0;
            }
        
        //general
        dp[l][s] = 0;
        if(dp[l+1][s]){
            dp[l][s] = 1;
        }
        if(s>=x[l] && dp[l][s-x[l]]){//taking it once for this call
            dp[l][s] = 1;
            }
        }
    }
    cout<<dp[0][m]<<'\n';
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
