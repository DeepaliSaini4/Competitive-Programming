/*
Problem Statement
Ibis is fighting with a monster.The health of the monster is H.Ibis can cast N kinds of spells. Casting the i-th spell decreases the monster's health by Ai, at the cost of 
Bi Magic Points.The same spell can be cast multiple times. There is no way other than spells to decrease the monster's health.
Ibis wins when the health of the monster becomes 0 or below. Find the minimum total Magic Points that have to be consumed before winning.

Constraints
1≤H≤10^4
 
1≤N≤10^3
1≤Ai≤10^4
1≤Bi≤10^4
All values in input are integers.

Input
Input is given from Standard Input in the following format:

H N
A1 
B1
​:
AN
​BN 
Output
Print the minimum total Magic Points that have to be consumed before winning.

Sample Input 1
9 3
8 3
4 2
2 1

Sample Output 1
4

---> Unbounded knapsack
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,H;
vector<int> magicpoints;
vector<int> healthdec;
int dp[1001][10001];

int rec(int level,int health){
    //base case
    if(health <= 0)
        return 0;
    if(level >= n) 
        return 1e18;
        
    //cache check
    if(dp[level][health]!=-1){
        return dp[level][health];
    }
    
    //compute
    // Try skipping current spell
    int points = rec(level + 1, health);
    // Try using current spell
    points = min(points, rec(level, health - healthdec[level]) + magicpoints[level]);
    
    //save and return
    return dp[level][health] = points;
}

void solver(){
    cin>>n>>H;
    
    memset(dp,-1,sizeof(dp));
    magicpoints.resize(n);
    healthdec.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>healthdec[i]>>magicpoints[i];
    }
    
    int ans = rec(0,H);
    if(ans >= 1e18)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    solver();
    return 0;
}
//not right spot the eerror in logic and return the right answer
