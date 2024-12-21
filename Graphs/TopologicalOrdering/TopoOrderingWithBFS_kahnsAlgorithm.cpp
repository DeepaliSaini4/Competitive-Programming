//Algorithm-->find the node which has indegree equal to zero add it to the initially empty topological ordering then remove it form the graph.
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>g;
vector<int>indeg;
vector<int> topo;
int n,m;
void kahn(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        topo.push_back(curr);
        for(auto v:g[curr]){
            indeg[v]--;
            if(indeg[v]==0){
                q.push(v);
            }
        }
        
    }
}
int main(){

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
// if graph contains cycle then the size of the topological ordering will nevr be n