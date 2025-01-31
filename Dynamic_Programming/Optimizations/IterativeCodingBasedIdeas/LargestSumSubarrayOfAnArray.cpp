/*
Q -> Find the largest sum subarray of an array.
*/
//----------> Recursive Code
#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
vector<int>arr;

int dp[101];
int rec(int level){//returns the best sum formed till index level
    //pruning
    //base case
    if(level<0) return 0;//invalid level
    //cache check
    if(dp[level]!=-1) return dp[level];
    //transiton
    int ans = -1e9;
    //taking the current entry
    ans = max(ans , rec(level-1)+arr[level]);
    //not taking the current entry
    ans = max(ans , arr[level];
    //save and return
    return dp[level] = ans;
}

void solver(){
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    //Form - 2--> returns the maximum sum subarray formed till the given index level.
    cout<<rec(n-1)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
//------------> Iterative Code
#include<bits/stdc++.h>
using namespace std;

void solver(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    long long last = -1e9;
    long long ans = -1e9;
    for(int i=0;i<n;i++){
      if(i==0){
          last = arr[i];
      }else{
          last= max(last,0LL)+arr[i];  
      }
      ans = max(ans, last);
    }
    cout<<ans<<endl;
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
