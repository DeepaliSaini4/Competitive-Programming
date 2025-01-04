#include <bits/stdc++.h>
using namespace std;
int n;
int w[3003];
int v[3003];
int W;

// O(n*W)--> cost to build it for the first time as followed by caching in the subsequent functionss
int dp[3003][3003];
int rec(int i,int x){ 
    //pruning
    //base case
    if(i==n){
        return 0;
    }
    //cache check
    if(dp[i][x]!=-1){
        return dp[i][x];
    }
    //transition
    int ans = 0; 
    for(int num_of_times=0;num_of_times<=x/w[i];num_of_times++){
        ans = max(ans,rec(i+1,x-num_of_times*w[i])+num_of_times*v[i]);
    }

    //save and return
    return dp[i][x] = ans;
}

void solver(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>W;
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,W)<<"\n";
   
}

int main()
{ solver();
    return 0;
}