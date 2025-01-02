/*
Description
You have given a graph G with n nodes and m edges. Each edge has an integer weight associated with. The weight of an edge may negative, positive or zero. If the graph contains a cycle with total weight > 0, print -1. Otherwise, find the weight of the highest weighted path from node 1 to n.

Input Format
The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1, 2, …, n.
Then, there are m lines describing the edges. Each line has three integers a, b and x: the edge starts at node a, ends at node b, and weight of the edge is x. All edges are unidirectional edges.
You can assume that it is possible to get from node 1 to node n.

Output Format
Print the answer on a new line.

Constraints
1 ≤ 2500 ≤ n
1 ≤ 5000 ≤ m
1 ≤ a, b ≤ n
−109 ≤ x ≤ 109

Sample Input 1
4 5
1 2 3
2 4 -1
1 3 -2
3 4 7
1 4 4

Sample Output 1
5

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define S second 
#define F first

int n,m;
vector<pair<int,pair<int,int>>>edge;
vector<int>dis;
bool is_cycle = false;

void bellmanford(int node){

    dis[node] = 0;
    //for n-1 times relax all the edges
        for(int i=0;i<n;i++){
             for(auto it:edge){
                 dis[it.S.F] = min(dis[it.S.F],dis[it.F]+it.S.S);
        }
    }
}

void solve(){
    bellmanford(1);

    //if any edge still gets relaxed it indicates the presence of negative cycle
    for(auto it:edge){
        if(dis[it.S.F] > dis[it.F]+it.S.S){
            is_cycle = true;
            break;
        }
    }
    if(is_cycle) cout<<"-1\n";
    else cout << -1*dis[n]<<'\n';
}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
     cin >> n >> m;

     for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge.push_back({a,{b,-c}});

    }
    
    dis.resize(n+1,1e18);

    solve();

    return 0;

}
//most weighted graph path = -(shortest path in transformed graph)