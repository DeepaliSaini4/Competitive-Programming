/*
Q -> Take any number of stones from any pile or take equal number of stones from both the piles at the same time.
If no stones left then lose . Player 1 starts the game. Find who wins if both the players play optimally.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int x,y;

int dp[1010][1010];
int rec(int x,int y){
    if(x==0  && y==0){
        return 0;
    }
    
    if(dp[x][y]!=-1) return dp[x][y];
    int win = 1;
    for(int i=1;i<=x;i++){
        if(rec(x-i,y) == 0){
            win = 1;
        }
    }
    for(int i=1;i<=y;i++){
        if(rec[x,y-i] == 0){
            win == 1;
        }
    }
    for(int i=1;i<=min(x,y);i++){
        if(rec(x-i,y-i)==0){
            win = 1;
        }
    }
    return dp[x][y] = win;
    
}
void solver(){
    cin>>x>>y;
    cout<<rec(x,y)<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}

//Time Complexity -> O(N^3).
