/*
Description
Given a directed graph with 
N vertices and M edges.
What is the minimum number of edges needed to reverse in order to have at least one path from vertex 
1 to vertex N, where the vertices are numbered from 
1 to 
N ?

Input Format
The first line contains 
T - the number of test cases.


The first line of each test case contains two space-separated integers 
N and 
M, denoting the number of vertices and the number of edges in the graph respectively.

Output Format
For each test case, In a single line, print the minimum number of edges we need to revert. If there is no way of having at least one path from 
1
1 to 
N
N, print -1.

Constraints

1≤T≤10

1≤N,M≤10 

There can be multiple edges connecting the same pair of vertices, There can be self-loops too i.e. 

Sample Input 1
1
7 7
1 2 
3 2
3 4
7 4
6 2
5 6
7 5

Sample Output 1
2
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define F first
#define S second

vector<vector<pii>>g;
vector<int>d; 
int m,n;


void bfs(int node){
    deque<int>pq;
    pq.push_back(node);
    d[node]=0;
    while(!pq.empty()){
        int node = pq.front();
        pq.pop_front();
        for(auto v:g[node]){
            if(d[v.F]> d[node]+v.S){
               d[v.F] = d[node] +v.S;
                if(v.S==0){
                    pq.push_front(v.F);
                }
                else{
                    pq.push_back(v.F);
                }
            }
        }
    }
}

void solver(){

    cin >> n >>m;

    g.resize(n+1);
    d.assign(n+1,1e9);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }

    bfs(1);

   if(d[n]!=1e9)cout<<d[n]<<'\n';
   else cout<<"-1\n";

   g.clear();
   d.clear();

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
