/*
Description:
You want to visit the country of Wonderland. There are N cities in the country. Not all cities are connected by roads, but you know which cities are connected.

You landed in city A, and you want to visit city B. You already booked your car, but it doesn’t have any petrol. The capacity of the tank of the car is C. You know the Per Liter cost of petrol in each city, and you also have the map of the country (i.e., you know the length of the road between two cities).

To travel one unit of distance, you need one liter of petrol.

Your task is to find the minimum cost to travel from city A to city B.

Input Format:
The first line of input contains N - the number of cities in the country of Wonderland.

The second line contains M - the number of roads in the country.

The next M lines each contain three integers u, v, and d:

There is a road between city u and v of length d.

The next line contains N space-separated integers:

P[1], P[2], ..., P[N] - where P[i] is the per liter cost of petrol in city i.


The last line of input contains three integers A, B, and C:

A: The starting city.

B: The destination city.

C: The capacity of the car's petrol tank.


It is guaranteed that it’s always possible to reach city B from city A.

Output Format:
Print the minimum cost to reach city B on a new line.

Constraints:
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ C ≤ 100
1 ≤ u, v ≤ N
1 ≤ d ≤ C
1 ≤ A, B ≤ N
1 ≤ P[i] ≤ 100

sample input:
5
5
1 2 1
2 3 1
3 4 1
4 5 1
1 4 6
1 10 10 10 1
1 5 8

6
6
1 2 1
2 3 1
3 4 1
4 5 1
1 6 1
6 5 5
10 10 10 10 1 1
1 5 8

ouput:
4
15

Note
Explanation 1:

Fill petrol of 4 liters in city 1, and travel via path 1 → 2 → 3 → 4 → 5.

Explanation 2:

Fill 1 liter of petrol in city 1 of cost 10, travel to city 6. Fill 5 liters of petrol at city 6 of cost 5 x 1 = 5. Travel to city 5. Total cost = 10 + 5 = 15. The path took 1 → 6 → 5.
*/

#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int,int>
#define F first
#define S second

using state = pair<int,int>; //{node,current amount of petrol}

int n,m;
vector<vector<pii>> g;
vector<int>pet;
int A, B, C;
vector<vector<int>> vis;
vector<vector<int>> dis;

void dijkstra(state st_node){
    priority_queue<pair<int,state>> pq; //{-distance,state}
    pq.push({0,st_node});
    dis[st_node.F][st_node.S]=0;
    while(!pq.empty()){
        auto x= pq.top();
        pq.pop();

        if(vis[x.S.F][x.S.S]==1) continue;
        vis[x.S.F][x.S.S] = 1;


        //try and go to neighbour city (if petrol allows)
        for(auto v:g[x.S.F]){
            if(x.S.S>=v.S){
                if(dis[v.F][x.S.S-v.S]>dis[x.S.F][x.S.S]+0){
                    dis[v.F][x.S.S-v.S]=dis[x.S.F][x.S.S]+0;
                    pq.push({-dis[v.F][x.S.S-v.S],{v.F,x.S.S-v.S}});
                }
            }
        }

        //refill the petrol if tank allows
        if(x.S.S<C){
            if(dis[x.S.F][x.S.S+1]>dis[x.S.F][x.S.S]+pet[x.S.F])
            {
                dis[x.S.F][x.S.S+1] = dis[x.S.F][x.S.S]+pet[x.S.F];
                pq.push({-dis[x.S.F][x.S.S+1],{x.S.F,x.S.S+1}});
            }
        }
    }
}

void solve(){
    state st_node = {A,0};
    dijkstra(st_node);

    state en_node = {B,0};
    cout<< dis[en_node.F][en_node.S]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    g.resize(n+1); //1-based
    for(int i=0;i<m;i++){
        int u, v, d;
        cin>>u>>v>>d;
        g[u].push_back({v,d});
        g[v].push_back({u,d});
    }
    pet.resize(n+1);
    for(int i=1;i<=n;i++) cin>>pet[i];
    cin >> A >> B >> C;
    vis.assign(n+1,vector<int>(C+1,0));
    dis.assign(n+1,vector<int>(C+1,1e18));

    solve();
    return 0;
}


