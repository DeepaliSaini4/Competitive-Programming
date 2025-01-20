/*
Q -> Description
You have a convex n-sided convex polygon where each vertex has an integer value vi. You are given an integer array values where v[i] is the value of the i thvertex (i.e., clockwise order).
You will triangulate the convex polygon into n−2 triangles. For each triangle, the value of that triangle is the product of the values of its vertices, and the total score of the triangulation is the sum of these values over all 
n−2 triangles in the triangulation.

Output the smallest possible total score that you can achieve with some triangulation of the polygon.

Input Format
First Line contains 
T - the number of test cases.
The First Line of each test case contains 
n - the number of vertices of the convex polygon.
The second line of each test case contains n space-separated values v[i] of the vertices in clockwise order.

Output Format
For each test case, Output the smallest possible total score that you can achieve with some triangulation of the polygon.

Constraints
1≤T≤10 
3≤n≤100
1≤v[i]≤10^4
 
Sum of n over all test cases is ≤5000.
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long 

void solver(){
    int n;
    cin>>n;
    // Vector to store matrix dimensions (1-based indexing)
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];

    // dp[l][r] = min cost to multiply matrices from index l to r
    vector<vector<int>>dp(n+1,vector<int>(n+1));

    // len = current chain length we're calculating
    for(int len = 3; len<=n;len++){
        // l = left end of current chain
        for(int l=1;l+len-1<=n;l++){
            // r = right end of current chain
            int r= l+len-1;
            int ans = 1e18;

            // x = position where we split the chain
            for(int x =l+1;x<=r-1;x++){
                // Cost = (multiply matrices at l,x,r) + (cost of left part) + (cost of right part)
                ans = min(ans,((v[l]*v[r]*v[x])+dp[l][x]+dp[x][r]));
            }
            dp[l][r] = ans;
        }
    }
    cout<<dp[1][n]<<'\n';
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
