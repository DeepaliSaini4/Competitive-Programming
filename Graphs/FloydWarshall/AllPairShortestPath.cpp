/*
Description
We have given an adjacency representation of a directed weighted graph and an array of vertices. At each iteration, a vertex is removed from the graph. Vertices are removed in the order given in the array. When the vertex is removed, all the edges that go in and out are also removed. 

Print the sum of all pairs shortest path just before each iteration.

Input Format
The first line contains integer n (1 ≤ n ≤ 500) — the number of vertices in the graph.
Next n lines contain n integers each — the graph adjacency matrix: the j-th number in the i-th line aij (1 ≤ aij ≤ 105, aii = 0) represents the weight of the edge that goes from vertex i to vertex j.
The next line contains n distinct integers: x1, x2, ..., xn (1 ≤ xi ≤ n) — the order of vertices removed from the graph.

Output Format
Print N space-separated numbers, where ith number represents the sum of all pairs shortest path just before ith removal.

Constraints
1 ≤ N ≤ 500

Sample Input 1
2
0 5
4 0
1 2

Sample Output 1
9 0

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 

int n;
vector<vector<int>>adj;
vector<int>rm;
vector<int>ans;

void floydWarshall(){
    for(int k=n;k>0;k--){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                adj[i][j]=min(adj[i][j],adj[i][rm[k]]+adj[rm[k]][j]);
            }
        }

    int apsp=0;
    for(int i=k;i<=n;i++){
             for(int j=k;j<=n;j++){
              apsp+=adj[rm[i]][rm[j]];  
            }
         }
        ans.push_back(apsp);
    }

}

void solver(){
    floydWarshall();
    for(int i=n-1;i>=0;i--){
        cout<<ans[i]<<" ";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;
    adj.resize(n+1,vector<int>(n+1,1e19));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>adj[i][j];
        }
    }

    rm.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>rm[i];
    }

    solver();

    return 0;
}
//come form future