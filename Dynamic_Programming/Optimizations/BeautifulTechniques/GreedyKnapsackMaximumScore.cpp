/*
Q -> There are n players every player can be in team A or team B. If person goes to team A his contribution
will be Ai. If a person goes to team B his contribution will be Bi. We need to maximize the total score of both the teams summed up together.
*/
#include<bits/stdc++.h>
using namespace std;

int n,a,b;
vector<pair<int,int>>arr;

int dp[101][101][101];
int rec(int i,int na,int nb){
    //pruning
    
    //base case
    if(i==n){
    if(na==a && nb==b) return 0;
    return -1e9;
    }
    //cache check
    if(dp[i][na][nb]!=-1) return dp[i][na][nb];
    //transition
    int score = rec(i+1,na,nb);
    if(na<=a) score = max(score,arr[i].first+rec(i+1,na+1,nb));
    if(nb<=b) score = max(score,arr[i].second+rec(i+1,na,nb+1));
    //save and return
    return dp[i][na][nb] = score;
}
int main(){
    cin>>n>>a>>b;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0,0)<<'\n';
    return 0;
}
