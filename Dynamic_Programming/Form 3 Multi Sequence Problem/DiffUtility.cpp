/*
Q -> Diff utility is the one which takes you from string X to string Y.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

string x,y;
int n,m;

int dp[5050][5050];
int rec(int l1,int l2){
    //check
    //base
    if(l1==n && l2==m) return 0;
    //cache check
    if(dp[l1][l2]!=-1) return dp[l1][l2];
    //calc
    int ans = 1e9;
    if(l1<n){//-x[l1]
        ans = min(ans,rec(l1+1,l2)+1);
    }
    if(l2<m){//+y[l2]
        ans = min(ans,rec(l1,l2+1)+1);
    }
    if(l1<n && l2<m && x[l1]==y[l2]){//x[l1]
        ans = min(ans,rec(l1+1,l2+1)+1);
    }
    //save ans return
    return dp[l1][l2] = ans;
}
void solve(){
    cin>>x>>y;
    n =x.length();
    m =y.length();
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
