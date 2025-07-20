class Solution {
public:
    bool bfs(vector<vector<int>>& graph,vector<int>&vis,int nod){
        queue<int>q;
        bool is_bipartite = 1;
        q.push(nod);
        vis[nod] = 1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:graph[node]){
                if(!vis[it]){
                    vis[it] = 3-vis[node];
                    q.push(it);
                }else if (vis[node]==vis[it]){
                    is_bipartite = 0;
                }
            }
        }
            return is_bipartite;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>vis(graph.size(),0);
        bool ans = true;
        for(int i=0;i<graph.size();i++){
            if(!vis[i])
           ans = (ans && bfs(graph,vis,i));     
        }
        return ans;
    }
};
