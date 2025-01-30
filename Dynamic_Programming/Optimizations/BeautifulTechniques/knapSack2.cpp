/*

Problem Statement
There are N items, numbered 1,2,…,N. For each i (1≤i≤N), Item i has a weight of wiand a value of vi.

Taro has decided to choose some of the 
N items and carry them home in a knapsack. The capacity of the knapsack is 
W, which means that the sum of the weights of items taken must be at most 
W.

Find the maximum possible sum of the values of items that Taro takes home.

Constraints
All values in input are integers.
1≤N≤100
1≤W≤10^9
 
1≤wi≤W
1≤vi≤10^3
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n,w;
const int inf = 1e9+7;
int weight[100];
int profit[101];

int dp[101][100100];
int rec(int level,int p){
  //base
  if(level==n){
    if (p==0) return 0;
    else return inf;
  }
  //cache check
  if(dp[level][p]!=-1)
  return dp[level][p];
  //transition
  int ans = rec(level+1,p);//skipped
  if(p>=profit[level]){
    ans = min(ans,rec(level+1,p-profit[level])+weight[level]);
  }
  //save and return
  return dp[level][p] = ans;
}
signed main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);
  cin>>n>>w;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++){
    cin>>weight[i]>>profit[i];
  }
  int ans =0;
  for(int prof =1;prof<=1e5;prof++){
   if(rec(0,prof)<=w) ans = prof;
  }
  cout<<ans<<'\n';
}
