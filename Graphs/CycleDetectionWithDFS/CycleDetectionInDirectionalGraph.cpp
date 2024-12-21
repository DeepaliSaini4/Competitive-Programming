#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>>g;
vector<int> col;
vector<int> parent;
bool is_cycle = 0;
vector<int> any_cycle;
void dfs(int node,int par){
    parent[node] = par;
    col[node]=2;
    for(auto v:g[node]){
        if(col[v]==1){
            // node - v is a forward edge
            dfs(v,node);
        } else if(col[v]==2){
            // node - v is a backward edge
            // we found a 
            cout<<"Hit: "<<node<<endl;
            if(is_cycle==0){
                int temp = node;
                while(temp!=v){
                 any_cycle.push_back(temp);
                 temp= parent[temp];
                }
               any_cycle.push_back(temp);
               reverse(any_cycle.begin(),any_cycle.end());
             }
          
            is_cycle =1;
        }
        else if(col[v] == 3){
            // node - v is a cross edge
        }
    }
    col[node]=3; 
}
signed main(){
    
    cin>>n>>m;
    g.resize(n+1);
    col.assign(n+1,1);
    parent.assign(n+1,1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }
    //Exploring every component
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            dfs(i,0);//no parent for the inital node
        }
    }
    for(auto v:any_cycle){
        cout<<v<<" ";
    }
}