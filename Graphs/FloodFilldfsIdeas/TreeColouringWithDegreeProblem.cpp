/*
Description
You have been given a tree with N nodes and N - 1 edges. You want to colour each node, such that no two adjacent nodes (directly connected by an edge) and no two nearly-adjacent nodes (both directly connected to a common node with edges) has the same colour. Your task is to find the minimum number of colours required to accomplished this.

Input Format
The first line of input contains N. Each of the remaining N−1 lines describes an edge in terms of the two nodes it connects.

Output Format
Print the minimum number of colours require.

Constraints
1 ≤ N ≤ 105
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

int n;
int d[100000];


void solver(){
    int max_deg=0;
    for(int i=0;i<n-1;i++){
        max_deg = max(max_deg,d[i]);
    }
    cout<<max_deg + 1<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    cin>>n;

    for(int i=0;i<n-1;i++){
        int a,b;
        cin >> a >> b;
        d[a--]++;
        d[b--]++;
    }
   
    solver();

    return 0;

}
/*
Concept: Degree of a tree

Framework: how to color tree so that no neighbors have same color?

Tactics: Number of distinct colors needed in a tree is equal to its (degree+1)

where degree = max number of children a node has in the tree.

Debug: checkout the constraints properly to declare the size of deg array.
*/