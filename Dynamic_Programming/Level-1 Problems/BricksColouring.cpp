/*
Q -> Description
You are given N bricks in a line and M different coloured buckets of paint. 
You have to find the number of ways you can colour the brick wall such that there are exactly K positions out of the N bricks such that it has a different colour from the brick wall on its immediate left.
(except the first brick, since there is no left brick). Print it modulo 10^9+7.

Input Format
The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first and only line of each test case contains three space-separated integers N, M, K.

Output Format
For each test case, print the number of ways you can colour the brick wall satisfying the given condition % 10^9+7.

Constraints
1≤ T ≤ 100
1≤ N, M ≤ 2000
0≤ K ≤ N-1

It is guaranteed that the sum of N*K over all test cases does not exceed 4*108.

Sample Input 1
3
3 2 2
2 2 1
3 5 0

Sample Output 1
2
2
5
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int mod = 1e9+7;
int n,m,k;

int dp[2001][2001];
//used form 1 intead fo form 2 as the left one decides the susequent bricks to the right
int rec(int level,int k_left){//returns the number of ways to colr bricks from level....n-1 with k_left transitions left.

    //base case
    if(level==n) return k_left==0;
    
    //cache check
    if(dp[level][k_left]!=-1) return dp[level][k_left];
    //compute
    int ways = 0;
    if(k_left>0)
    ways += rec(level+1,k_left-1)*(m-1)%mod;
    ways +=(rec(level+1,k_left))%mod;
    //save and return
    return dp[level][k_left] = ways;

}
void solver(){
    cin>>n>>m>>k;
    memset(dp,-1,sizeof(dp));
    if(m==1&& k>0){
        cout<<0<<'\n';
    }
    else{
        cout<<(m*rec(1,k))%mod<<'\n';//have m possible colors for the initial brick
    }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    solver();
    return 0;
}
