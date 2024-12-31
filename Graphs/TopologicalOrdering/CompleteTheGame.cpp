/*
Description
A game has n levels, connected by m teleporters, and your task is to get from level 1 to level n. The game has been designed so that there are no directed cycles in the underlying graph. In how many ways can you complete the game?

Input Format
The first input line has two integers n and m: the number of levels and teleporters. The levels are numbered 1, 2, …, n.
After this, there are m lines describing the teleporters. Each line has two integers a and b: there is a teleporter from level a to level b.

Output Format
Print one integer: the number of ways you can complete the game. Since the result may be large, print it modulo 109+7.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
4 5
1 2
2 4
1 3
3 4
1 4

Sample Output 1
3
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

vector<vector<int>>g;
vector<int>indeg;
vector<int> topo;
vector<vector<int>>predge;
int MOD = 1e9+7;
vector<int>dp; //dp[i]-->Stores the number of paths reaching the ith node
int n,m;

void kahn(){
    queue<int> pq;
   for(int i=1; i<=n; i++) {
        if(indeg[i] == 0) pq.push(i);
    }

    while(!pq.empty()){
        int x = pq.front();
        pq.pop();
        topo.push_back(x);
        for(auto v:g[x]){
            indeg[v]--;
            if(indeg[v]==0)
            pq.push(v);
        }
    }
}

void solver(){
    kahn();
    dp[1] = 1;
    for(auto v:topo){
        for(auto it:predge[v]){
            dp[v] = (dp[v] + dp[it] )%MOD;
        }
    }
    cout<<dp[n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;

    g.resize(n+1);
    indeg.assign(n+1,0);
    predge.resize(n+1);
    dp.resize(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
        predge[b].push_back(a);
    }

    solver();

    return 0;
}
