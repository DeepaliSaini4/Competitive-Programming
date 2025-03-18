/*
Description
Given a tree of N nodes and an array A of length N corresponding to the value of the nodes.
You have to answer Q queries. In each query, two nodes are given x, y→ find the gcd of nodes present on the shortest path from x to y.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

vector<vector<int>>g;//to store the adj list
vector<int>val;// to store the val corresponding to each node
vector<int>dep;// to store the depth 
vector<vector<int>>par;// to store the 2^i th parent of each node
vector<vector<int>>dp;// Stores the GCD of the path up to the 2^i-th ancestor


int gcd(int a,int b){
    if(a==0 || b==0) return a + b;
    return gcd(b,a%b);
}

void dfs(int node,int parent,int depth){
    dep[node] = depth;
    par[node][0] = parent;
    dp[node][0] = val[node];

     // Precomputing 2^i-th ancestor and GCD values for binary lifting
    for(int i=1;i<20;i++){
        if(par[node][i-1]!=-1){ //ancestor is valid
        par[node][i] = par[par[node][i-1]][i-1];// Compute the 2^i-th ancestor of 'node' using the previously computed (2^(i-1))-th ancestor

        // Compute the GCD of the path from 'node' to its 2^i-th ancestor using the precomputed values for (2^(i-1))-th ancestor
        dp[node][i] = gcd(dp[node][i-1],dp[par[node][i-1]][i-1]);
        }
        else
        par[node][i] = -1;//no valid ancestor, mark as -1
    }
     // DFS traversal to process child nodes
    for(auto it:g[node]){
        if(it!=parent){
            dfs(it,node,depth + 1);
        }
    }
}

// Function to compute the GCD of the path between two nodes a and b
int pathgcd(int a,int b){
    //making a the larger depth one 
    if(dep[a] < dep[b]) swap(a,b);

    //bringing to the same level
    int ans = 0;

    //brining to the same level while aggregating the gcd
    for(int i=19;i>=0;i--){
        if((dep[a]-dep[b]) & (1<<i)){
            ans = gcd(ans,dp[a][i]);
            a = par[a][i];
        }
    }
    //if they converge to same node
    if(a==b) return gcd(ans,val[a]);

    //binary lifting 
    for(int i=19;i>=0;i--){
        //performing till the donot merge to the same parent
        if(par[a][i]!=par[b][i]){
            ans = gcd(ans,dp[a][i]);
            ans = gcd(ans,dp[b][i]);
            a = par[a][i];
            b = par[b][i];
        }
    }
    // Final aggregation including LCA and its children
    return gcd(ans,gcd(val[a],gcd(val[b],val[par[a][0]])));
}

void solver(){
    int n;
    cin>>n;

    par.assign(n+1,vector<int>(20,-1));
    dp.assign(n+1,vector<int>(20,-1));
    dep.assign(n+1,0);

    val.assign(n+1,0);
    for(int i=1;i<=n;i++) cin>>val[i];

    g.assign(n+1,vector<int>());
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1,0); //starting node is 1 not 0 as 0 is the pseudo node now
    int q;
    cin>>q;
    while(q--){
        int a,b;
        cin>>a>>b;
        cout<<pathgcd(a,b)<<'\n';
    }
        dp.clear();
        par.clear();
        val.clear();
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();

    return 0;
}
