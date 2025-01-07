/*
Q-> There are N items (N<=100 and Xi<=10^4).
X1, X2, X3, X4, X5, ........Xn.
Find if a subset of items exists that sums up to the target.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n;
int t;
int x[101];
int dp[105][10100];

int rec(int level,int taken){
   //pruning
   if(taken>t) return 0;
   //base case
   if(level == n+1){
       if(t==taken){
           return 1;
       }else{
           return 0;
       }
   }
   //cache check
   if(dp[level][taken]!=-1){
       return dp[level][taken];
   }
   
   
   //transition/compute
   int ans =0;
   if(rec(level+1,taken)==1){
       ans = 1;
   }else if(rec(level+1,taken+x[level])){
       ans = 1;
   }
   
   //save and return
   return dp[level][taken] = ans;
}

void solver(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    cin>>t;
    memset(dp,-1,sizeof(dp));
    cout<<rec(1,0);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    solver();
    
    return 0;
}