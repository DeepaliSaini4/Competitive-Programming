class Solution {
public:
    bool is_b = true;
    bool dfs(vector<vector<int>>& g,vector<int>&vis,int node){
        for(auto it:g[node]){
            if(!vis[it]){
                vis[it] = 3 - vis[node];
                dfs(g,vis,it);
            }else if(vis[it]==vis[node]){
                is_b = false;
                break;
            }
        }
        return is_b;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>vis(n,0);
        bool ans = true;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                ans = ans && dfs(graph,vis,i);
            }
        }
        return ans;
    }
};
