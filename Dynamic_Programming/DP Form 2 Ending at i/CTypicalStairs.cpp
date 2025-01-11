/*
Problem Statement
There is a staircase with 
N steps. Takahashi is now standing at the foot of the stairs, that is, on the 
0-th step. He can climb up one or two steps at a time.

However, the treads of the 
a1-th, a2-th, a 3-th, …, a M -th steps are broken, so it is dangerous to set foot on those steps.
How many are there to climb up to the top step, that is, the N-th step, without setting foot on the broken steps? Find the count modulo 1 000 000 007.

Constraints
1≤N≤10^5
 0≤M≤N−1
1≤a1 <a2< ... <aM ≤N−1
Input
Input is given from Standard Input in the following format:

N M
a1
​a2
.
.
.
aM
​Output
Print the number of ways to climb up the stairs under the condition, modulo 
1 000 000 007.

Sample Input 1
6 1
3

Sample Output 1
4
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<bool>broken;
int dp[10001];

int rec(int level){ //returns all the ways to reach the current level 

    //pruning
    if(level<0) return 0;
    if(broken[level]) return 0;
    
    //base case
    if(level ==0) return 1;
    
    //cache check
    if(dp[level]!=-1){
        return dp[level];
    }
    
    //compute
    int ans =rec(level -1);
    if(level -2>=0){
        ans +=rec(level-2);
    }
    
    //save and return
     return dp[level] = ans;
}
void solver(){
    cin>>n>>m;
    broken.resize(n+1,0);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        broken[b]=1;//keeping broken as a bool value
    }
    cout<<rec(n)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
