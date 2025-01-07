/*
Q-> There are N items (N<=100 and Xi<=10^4).
X1, X2, X3, X4, X5, ........Xn.
Find if a subset of items exists that sums up to the target.
Have t such querries.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n;
int t;
int x[101];
int dp[105][10100];

int rec(int level,int left){
   //pruning
   if(left<0) return 0;
   //base case
   if(level == n+1){
       if(left==0){
           return 1;
       }else{
           return 0;
       }
   }
   //cache check
   if(dp[level][left]!=-1){
       return dp[level][left];
   }
   
   
   //transition/compute
   int ans =0;
   if(rec(level+1,left)==1){
       ans = 1;
   }else if(rec(level+1,left - x[level])){
       ans = 1;
   }
   
   //save and return
   return dp[level][left] = ans;
}

void solver(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
     memset(dp,-1,sizeof(dp)); //O(#S) + O(DP)
    int q;
    cin>>q;
    while(q--){//O(q)
         cin>>t;
         cout<<rec(1,t);
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    solver();
    
    return 0;
}
