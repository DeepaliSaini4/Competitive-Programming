// Max Skill gained in time X by Solving K slot Questions using Dp.
#include<bits/stdc++.h>
using namespace std;

int n;
int t[1001];
int s[1001];
int x,k;

int dp[101][101][101];


int rec(int level,int timetaken, int itemtaken){//max skill i can make from[level..n-1]..if [0..level-1] is decided.
    // and parameters mean from [0....level-1]
    //level-->current item in [0....n-1]
    //pruning
    //base case
    if(level == n){
        return 0;  //what is the max skill you can make out of empty cell
    }
    //cache check
    if(dp[level][timetaken][itemtaken]!=-1){
        return dp[level][timetaken][itemtaken];
    }
    
    //transition
    int ans = rec(level+1,timetaken,itemtaken);
    //check for taking the item
    if(timetaken + t[level] <= x && itemtaken +1 <= k){
        ans = max(ans,s[level]+rec(level+1,timetaken+t[level],itemtaken+1));
    }
    //save and return
    return dp[level][timetaken][itemtaken] = ans;
}

void solver(){
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>t[i]>>s[i];
    }
    
    cin>>x>>k;
    
    memset(dp,-1,sizeof(dp));
    
    cout<<rec(0,0,0)<<endl;
   
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    solver();
    
    return 0;
}