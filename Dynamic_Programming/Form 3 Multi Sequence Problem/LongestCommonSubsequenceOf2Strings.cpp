#include<bits/stdc++.h>
using namespace std;

#define int long long
int n,m;
string a,b;

int dp[1001][1001];
int rec(int i,int j){
    //return the LCS of a[i...n-1] and b[j...m-1]
    //pruning
    
    //base case
    if(i>=n || j>=m) {
        return 0;
    }
    //cache check
    if(dp[i][j]!=-1) return dp[i][j];
    //compute
    int ans =0;
    ans = max(ans,rec(i+1,j));
    ans = max(ans,rec(i,j+1));
    if(a[i]==b[j]){
        ans = max(ans,1+rec(i+1,j+1));
    }
    
    //save and return
    return dp[i][j] = ans;
}

void solver(){
    cin>>n>>m;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
/*TC = O(N*M)

Input:
6 7
AGGTAB
GXTXATB

Output:4*/