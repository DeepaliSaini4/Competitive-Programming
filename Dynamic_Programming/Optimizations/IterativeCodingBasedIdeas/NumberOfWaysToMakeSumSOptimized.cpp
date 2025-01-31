/*
Q -> There are n sliders such that slider a1 can be slided upto a1 and so on.
0......a1, 0.......a2, 0.......an. Find the number of ways in which the sliders
can be arranged to make the sum upto s.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long 
void solver(){
    int n,s;
    cin>>n>>s;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
   int dp[n+1][s+1];
   
   dp[n][0] = 0;
   
  for(int level=n;level>=0;level--){
      for(int sum_left=0;sum_left<=s;sum_left++){
        
         dp[level][sum_left] = dp[level+1][sum_left];
         if(sum_left-arr[level]-1>=0) dp[level][sum_left] -=dp[level+1][sum_left-arr[level]-1];
        
         for(int sum_left=1;sum_left<=s;sum_left++){
             dp[level][sum_left]+=dp[level][sum_left-1];
         }
     }
  }
  cout<<dp[0][s]-dp[0][s-1]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
// tc = o(n*s);
