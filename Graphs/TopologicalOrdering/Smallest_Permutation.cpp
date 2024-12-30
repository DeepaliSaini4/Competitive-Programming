/*
Description
Among the sequences 
P
P that are permutations of 
(1,2,…,N) and satisfy the condition below, find the lexicographically smallest sequence.

For each M
i=1,…,M, 

 Ai appears earlier than Bi in P else cout -1;

Input Format
Input is given from Standard Input in the following format:

Output Format
Print the answer.

Constraints

2≤N≤2×10 

1≤M≤2×10 


All values in input are integers.
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n,m;
vector<vector<int>>g;
vector<int> indeg;
vector<int> topo;

void kahn(){
    priority_queue<int>pq;
    for(int i=1; i<=n;i++){
        if(indeg[i]==0)pq.push(-i);
    }
    while(!pq.empty()){
        int x = -pq.top();
        pq.pop();
        topo.push_back(x);

        for(auto v:g[x]){
            indeg[v]--;
            if(indeg[v] == 0) pq.push(-v);
        }

    }
}
void solver(){
    kahn();

    if(topo.size()!=n) cout<<"-1\n";
    else{
        for(auto it:topo) cout<<it<<" ";
        cout<<'\n';
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    g.resize(n+1);
    indeg.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;
    }

    int n;
    cin>>n;

    solver();

    return 0;

}