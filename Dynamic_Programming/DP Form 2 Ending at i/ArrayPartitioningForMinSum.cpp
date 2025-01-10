/*
DP form - 1. Practice Question one
Q--> Given an array of size N divide it into K subarrays such 
that the sum of minimium of all subarrays reduces to minimum.
*/
#include<bits/stdc++.h>
using namespace std;


int n,k;
int arr[1001];
int dp[1001][101];

int rec(int i,int x){
    //pruning
    if(x<0){
        //invalid
        return 1e9;
    }
 
    //base case
    if(i==-1){
        if(x==0){
            return 0;
        }else{
            //invalid case
            return 1e9;
        }
    }
    //cache check
    if(dp[i][x]!=-1)
    return dp[i][x];
    
    //transition
    int ans = 1e9;
    int min_seen = arr[i];
    for(int j=i-1;j>=-1;j--){
        ans = min(ans,rec(j,x-1) + min_seen);
        min_seen = min(min_seen,arr[j]);
    }
    //save and return
    return dp[i][x] = ans;
}

void solve(){
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(n-1,k)<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solve();
    return 0;
}