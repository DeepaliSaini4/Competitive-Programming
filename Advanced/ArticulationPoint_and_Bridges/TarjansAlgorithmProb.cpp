/*
Q -> Find the product of size of component of a graph after
1. Deleting each node
2. Deleting each edge
*/
#include <bits/stdc++.h>
using namespace std;
 
int n,m;
vector<int> g[200200];
 
// for each node.
int vis[200200];
int comp_num[200200];
int comp_size[200200];
 
int subtree_sz[200200];
 
 
 
// tarjan's algo related
int tin[200200];
int low[200200];
int timer = 1;
 
vector<int> child[200200];
int par[200200];
 
 
int ans[200200];
 
 
void dfs(int nn,int pp,int comp_n){
    vis[nn] = 1;
    par[nn] = pp;
    // component num and sizing
    comp_num[nn] = comp_n;
    comp_size[comp_n]++;
    subtree_sz[nn] = 1;
    // tarjan related
    tin[nn] = low[nn] = timer++;
    
    for(auto v:g[nn]){
        if(v!=pp){ // v is a child or backedge
            if(vis[v]){
                // its a backedge
                low[nn] = min(low[nn],tin[v]);
            }else{
                // its a forward edge
                dfs(v,nn,comp_n);
                subtree_sz[nn]+=subtree_sz[v];
                low[nn] = min(low[nn],low[v]);
                child[nn].push_back(v);
            }
        }
    }
}
 
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    int comp_n=1;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,-1,comp_n);
            comp_n++;
        }    
    }
    
    int global_ans = 1;
    for(int cc = 1;cc<comp_n;cc++){
        global_ans *= comp_size[cc];
    }
    
    for(int nn = 1;nn<=n;nn++){
        ans[nn] = global_ans;
        ans[nn] /= comp_size[comp_num[nn]];
        if(par[nn]==-1){
            // root 
            for(auto v:child[nn]){
                ans[nn] *= subtree_sz[v];
            }
        }else{
            // normal node
            int par_size = comp_size[comp_num[nn]] - 1;
            for(auto v:child[nn]){
                if(low[v]>=tin[nn]){
                    // v gets disconnected when nn is deleted.
                    ans[nn] *= subtree_sz[v];
                    par_size -= subtree_sz[v];
                }
            }
            ans[nn] *= par_size;
        }
        cout<<nn<<" : "<<ans[nn]<<endl;
    }
    return 0;
}
