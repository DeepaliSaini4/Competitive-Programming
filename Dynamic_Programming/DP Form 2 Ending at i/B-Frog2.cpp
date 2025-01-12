/*
Q -> There are N stones, numbered 1,2,…,N. For each i (1≤i≤N), the height of Stone i is hi.
There is a frog who is initially on Stone 
1. He will repeat the following action some number of times to reach Stone N:If the frog is currently on Stone i, jump to one of the following: Stone 
i+1,i+2,…,i+K. Here, a cost of ∣hi−hj∣ is incurred, where j is the stone to land on.
Find the minimum possible total cost incurred before the frog reaches Stone N.

Constraints
All values in input are integers.
2≤N≤10^5
 1≤K≤100
1≤hi≤10^4
 
Input
Input is given from Standard Input in the following format:

N K
h1
h2
… 
hN

​Output
Print the minimum possible total cost incurred.

Sample Input 1
5 3
10 30 40 50 20

Sample Output 1
30
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,k;
vector<int>height;
int dp[10001];

int rec(int level){//returns the minimum cost required to reach N from the given level
    //pruning
    if(level>=n-1) return 0; //no cost for unavaible index
    //base case
    //cache check
    if(dp[level]!=-1)
    return dp[level];
    //compute
    int mincost =1E9;
    for(int i=level+1;i<=min(level+k,n-1);i++){
        int cost=(abs(height[level]-height[i])+rec(i));
        mincost = min(cost,mincost);
    }
    //save and return
    return dp[level] = mincost;
}

void solver(){
    cin>>n>>k;
    height.resize(n);
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++){
        cin>>height[i];
    }
    cout<<rec(0);//returns the minimum cost to reach N from the given level
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
