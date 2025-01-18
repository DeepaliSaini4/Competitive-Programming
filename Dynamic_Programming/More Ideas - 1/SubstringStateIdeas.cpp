#include<bits/stdc++.h>
using namespace std;

#define int long long 

string t = "0100";
int n;

int dp[100100][16];
int rec(int level,int lastthree){//valid binary strings by filling the level from [level........n-1]
   //base case
   if(level == n) return 1;
   //caching
   if(dp[level][lastthree]!=-1) return dp[level][lastthree];
   //transition
   int ans =0;
   if(level>=3 && lastthree==2){//0101
   //dont allow
        ans = rec(level+1,5);
   }
   else{
       //add a zero
       ans  = rec(level+1,(lastthree<<1|0)&7);//gives the last three bits maintained here
       ans += rec(level+1,(lastthree<<1|1)&7);
   }
   //save and return
    return dp[level][lastthree] = ans;
   
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
