/*
Q-> Find the number of N length binary string that doesn't contain the subsequence
"0100"
*/
//------------------> FORM - 1 APPROACH
#include<bits/stdc++.h>
using namespace std;

#define int long long 

string t = "0100";
int n;

int dp[100100][5];
int rec(int level,int match){//how much of prefix of the string t matched till the current level
    //pruning
    if(match==4) return 0;
    //base case
    if(level==n) return 1;
    //cache check
    if(dp[level][match]!=-1) return dp[level][match];
    //transition
    int ans = rec(level+1,match+1) + rec(level+1,match);
    //save and return
    return dp[level][match] = ans;
}

void solver(){
    cin>>n;
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}