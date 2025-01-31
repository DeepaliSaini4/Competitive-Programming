/*
Q -> There are n sliders such that slider a1 can be slided upto a1 and so on.
0......a1, 0.......a2, 0.......an. Find the number of ways in which the sliders
can be arranged to make the sum upto s.
*/
//----------->Recursive Code
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,s;
vector<int>arr;

int dp[101][101];
int rec(int level,int sum_left){//returns the count of the number of times sum s can be formed from [level...n-1]
    //pruning
  if(sum_left<0) return 0;
    //base case
    if(level==n){
        if(sum_left==0){
            return 1;
        }
        return 0;
    }
    //cache check
    if(dp[level][sum_left]!=-1) return dp[level][sum_left];
    //transition
    int cnt = 0;//always initialize to avoid occurring of garbage value
    for(int taken = 1;taken<=arr[level];taken++){
        //take from the current level
        cnt += rec(level+1,sum_left-taken);
    }
    //skip the current level
        cnt +=rec(level+1,sum_left);
    //save and return
    return dp[level][sum_left] = cnt;
}

void solver(){
    cin>>n>>s;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,s);//returns the count of the times sum 's' can be formed from [0....n-1].
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
//----------------> Iterative Code
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n,s;
vector<int>arr;
void solver(){
    cin>>n>>s;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int dp[n+1][s+1];
  for(int level=n;level>=0;level--){
      for(int sum_left=0;sum_left<=s;sum_left++){
          if(level == n){
            if(sum_left == 0) dp[level][sum_left] = 1;
            else dp[level][sum_left] = 0;
            continue;
        }
         dp[level][sum_left] = 0;
        for(int x=0;x<=arr[level];x++){
           if(sum_left>=x) {
               dp[level][sum_left] +=dp[level+1][sum_left-x];
            }
        }
     }
  }
  cout<<dp[0][s]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
