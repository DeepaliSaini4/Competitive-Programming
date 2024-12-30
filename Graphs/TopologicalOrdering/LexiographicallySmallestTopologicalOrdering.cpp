//Lexiographically smallest topological ordering
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>g;
vector<int>indeg;
vector<int> topo;

int n,m;

void kahn(){
    priority_queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(-i);
    }
    while(!q.empty()){
        int curr = -q.top();
        q.pop();
        topo.push_back(curr);
        for(auto v:g[curr]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(-v);
            }
        }
        
    }
}
signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;

    g.resize(n+1);
    indeg.assign(n+1,0);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        indeg[b]++;//as the edge is from a-->b
    }

    kahn();

    if(topo.size()!=n){
        cout<<"Cycle Detected!"<<endl;
    } 

    else{
    for(auto v:topo){
        cout<<v<<" ";
       }
    }
}
//small tweek in topological odering by bfs use a priority qeueue.