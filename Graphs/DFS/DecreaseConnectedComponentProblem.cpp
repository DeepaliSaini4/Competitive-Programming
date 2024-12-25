/*
Description
You have given an undirected graph with n nodes, and m edges between them. The goal is to add exactly one edge between two nodes such that the total number of connected components in the graph decreases. Your task is to find out the number of ways to add such edge.

Input Format
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
After that, there are m lines describing the edges. Each line has two integers a and b: there is an edge between those nodes.
An edge always connects two different nodes, and there is at most one edge between any two nodes.

Output Format
Print the number of ways to add such edge, described in the statement.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5 4
1 2
2 3
1 3
4 5
Sample Output 1
6
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
vector<vector<int>>g;
vector <int> vis;
int cnt;
int n,m;

void dfs(int node){
    vis[node]=1;
    cnt++;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v);
        }
    }
}
void solver(){
    int sum=0;
    int sqsum=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt=0; // tracks the size of the component
            dfs(i);
            sum +=cnt;
            sqsum += cnt*cnt;
        }
    }
    cout<< (((sum*sum)-sqsum)/2)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    g.resize(n+1);
    vis.assign(n+1,0);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    solver();

    return 0;
}
/*
Tactics--> formula--> SOP= ((sum)^2-(sum of squares))/2
Debug--> indexing while looping for nodes should be from 1 to n (1 based indexing).
*/