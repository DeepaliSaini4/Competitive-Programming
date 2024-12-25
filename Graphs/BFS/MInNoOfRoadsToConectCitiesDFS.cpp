/*
Description
Zenithland has n cities and m roads between them. The goal is to construct new roads so that there is a route between any two cities. A road is bidirectional. Your task is to find out the minimum number of roads required.

Input Format
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1, 2, …, n.
After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
A road always connects two different cities, and there is at most one road between any two cities.

Output Format
Print the number of minimum roads required.

Constraints
1 ≤ n ≤ 105
1 ≤ m ≤ 2 x 105
1 ≤ a, b ≤ n

Sample Input 1
4 2
1 2
3 4

Sample Output 1
1

*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>g;
vector<int>vis;
int m,n;

void dfs(int node){
  vis[node] = 1;
  for(auto v:g[node]){
    if(!vis[v]){
      dfs(v);
    }
  }
}

void solver(){
    int compo_nu=0;
    for(int i=1;i<=n;i++){
      if(!vis[i]){
        compo_nu++;
        dfs(i);
      }
    }
    cout<<(compo_nu-1)<<'\n';
}

signed main(){

  ios_base::sync_with_stdio(0);
  cin.tie(0);cout.tie(0);

  cin>>n>>m;

  g.resize(n+1);
  vis.assign(n+1,0);

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
Debug: Access the graph nodes from one to n while performing dfs.
*/