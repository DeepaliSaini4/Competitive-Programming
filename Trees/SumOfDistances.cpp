/*
Description
You are given a tree consisting of n nodes. d(u, v) is the distance between nodes u and v, or number of edges in between the path connecting two nodes u and v. Your task is to find the sum of distances over all possible pairs of nodes.

Input Format
The first input line contains an integer n: the number of nodes. The nodes are numbered 1, 2, …, n. Then there are n − 1 lines describing the edges. Each line contains two integers a and b: there is an edge between nodes a and b.

Output Format
Print the sum as mentioned in the problem statement.

Sample Input 1
5
1 2
1 3
3 4
3 5

Sample Output 1
18
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>graph;
int ans = 0;

int dfs(int curr,int par,int n){
    int sum = 0;
    for(auto u:graph[curr]){
        if(u == par) continue;
        sum += dfs(u, curr, n);
    }
    sum++;
    ans += 1LL * sum * (n-sum);
    return sum;
}

void solver(){
    int n;
    cin>>n;

    graph.assign(n + 1, vector<int>()); 

    for(int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,-1,n);
    cout<<ans<<'\n';

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    solver();

    return 0;
    
}
