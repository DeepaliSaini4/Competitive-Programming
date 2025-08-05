#include<bits/stdc++.h>
using namespace std;

bool issafe(int node,int color[],bool graph[101][101],int m,int n,int i){
    for(int k=0;k<n;k++){
        if(k!=node&& graph[k][node]==1 && color[k]==i) return false;
    }
    return true;
}

bool solve(int node,int color[],int m, int n, bool graph[101][101]){
    //base case or returning case
    if(node==n) return true;
    //choice -> m colors 
    for(int i=1;i<=m;i++){
        if(issafe(node,color,graph,m,n,i)){
            color[node] = i;//coloring the node
           if(solve(node+1,color,m,n,graph))return true;
           color[node] = 0;//backtrack
        }
    }
    return false;
}

//Function to determine if graph can be coloured with at most M colours such
//that no two adjacent vertices of graph are coloured with same colour.
bool graphColoring(bool graph[101][101], int m, int N) {
  int color[N] = {0};
  if (solve(0, color, m, N, graph)) return true;
  return false;
}

int main() {
  int N = 4;    //0,1,2,3
  int m = 3;    //atmost m colors

  bool graph[101][101];
  memset(graph, false, sizeof graph);

  // Edges are (0, 1), (1, 2), (2, 3), (3, 0), (0, 2)
  graph[0][1] = 1; graph[1][0] = 1;
  graph[1][2] = 1; graph[2][1] = 1;
  graph[2][3] = 1; graph[3][2] = 1;
  graph[3][0] = 1; graph[0][3] = 1;
  graph[0][2] = 1; graph[2][0] = 1;
  
  cout << graphColoring(graph, m, N);

}
//TC=O(m^N)
