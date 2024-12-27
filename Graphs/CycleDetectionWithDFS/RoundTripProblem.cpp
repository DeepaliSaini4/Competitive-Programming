/*
Description
Zenithland has n cities and m roads between them. Your task is to check for the existence of a round trip that begins in a city, goes through two or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.

Input Format
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.

Output Format
Print ‘YES’ if such round trip exists, otherwise print ‘NO’.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Sample Output 1
YES
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>g;
vector<int>vis;
vector<int>par;
int n,m;
bool is_cycle=0;

void dfs(int node,int parent){
    vis[node]=1;
    par[node] = parent;
    for(auto v:g[node]){
        if(!vis[v]){
            dfs(v,node);
        }
       else if(vis[v]==1 && v!=par[node]){
           is_cycle=1;
            break;
        }
    }
}

void solver(){
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
            if(is_cycle){
                cout<<"YES"<<'\n';
                return;
            }
        }
    }
    if(is_cycle)cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    g.resize(n+1);
    vis.assign(n+1,0);
    par.assign(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    solver();

    return 0;

}
/*
Debug: If assigning the size of graph beforehand for the cols like this--> g.assign(n+1,vector<int>(m+1)); then while taking input for the graph instead of push back use the assignment operator.
*/