/*
Description
You have given an undirected graph of N vertices and M edges. Edge weight d on edge between nodes u and v represents that u and v are connected by a thread of length d units. 
You set node A on to the fire. It takes to fire 1 unit of time to travel 1 unit of distance via threads.
Let T be the minimum time in which all the threads will be burned out. 

Your task is to find 10T. We can prove that 10T will always be an integer number.

See the sample test cases for more explanation.

Input Format
The first line of input contains N - the number of nodes in the graph.
The second line contains M - the number of edges in the graph.
Next M lines contain three integers u, v, d - there is a thread between node u and v of length d.
The last line of input contains A - the node on which we set fire.

It’s guaranteed that graph is connected.

Output Format
Print the value of 10T.

Constraints
1 ≤ N ≤ 2 x 105
1 ≤ M ≤ 2 x 105
1 ≤ u, v ≤ N
1 ≤ d ≤ 109

Sample Input 1
2
1
1 2 2
1

Sample Output 1
20

Sample Input 2
3
3
1 2 2
2 3 2
1 3 6
1

Sample Output 2
50

Sample Input 3
3
3
1 2 2
1 3 2
2 3 1
1

Sample Output 3
25

*/
//To burn the entire graph, we need to wait until the last edge burns completely, so the solution finds the **maximum burn time among all edges.

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define F first
#define S second


int m,n,A;
vector<vector<pair<int,int>>>g;
vector<int>dis;                 //To Store the minimum time
vector<int>vis;
vector<pair<pair<int,int>,int>>re;//{{node1,node2},edge};

void dikstra(int node){
    priority_queue<pair<int,int>> pq;
    pq.push({-0,node});  //{distance,node}
    dis[node] = 0;
    while(!pq.empty()){
        int x = pq.top().S;
        pq.pop();
        if(vis[x]) continue;
        vis[x] = 1;
        for(auto v:g[x]){
            if(dis[v.F]>dis[x]+v.S){
                dis[v.F] = dis[x]+ v.S;
                pq.push({-dis[v.F],v.F});
            }
        }
    }
}

void solver(){
    dikstra(A);

    double max_time=0;
    //traverse through all the edges and find the max time
    for(auto it:re){
        int t1 = dis[it.F.F];
        int t2 = dis[it.F.S];
        int len= it.S;
        
        double time;

        if ((abs(t1-t2))>=len){
            //relaxing time about the length
            time=(min(t1,t2)+len);
        }else{
            time= ((t1+t2+len)/2.0);
        }
        max_time = max(max_time,time);
    }
    cout<<(int)(max_time*10)<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    g.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
        re.push_back({{a,b},c});
    }

    cin>>A; //Starting node

    dis.resize(n+1,1e18);
    vis.resize(n+1,0);

    solver();

    return 0;
}