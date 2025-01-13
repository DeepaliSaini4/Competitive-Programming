/*
Description
Given a grid of size n*m with 0s and 1s, you need to find the area of the largest square containing only 1.

Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the next n lines contains m space-separated integers, aij - the number at that cell.

Output Format
For each test case, print the maximum area.

Constraints
1 ≤ t ≤ 105

1 ≤ n, m ≤ 103

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 10^7.

Sample Input 1
3
2 3
0 1 1
0 0 0
3 3
1 0 1
0 1 1
0 1 1
2 2
0 0
0 0

Sample Output 1
1
4
0
 */
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int n,m;
vector<vector<int>>grid;
vector<vector<int>>dp;

int rec(int i,int j){//returns the side of the largest square formed by keeping i,j as the rightmost cell
    //pruning
    if(i<0 || j<0) return 0;

    //base case
    if(i==0 && j==0) {
        if(grid[0][0]==0) return 0;
        else return 1;
    }

    //cache check
    if(dp[i][j]!=-1) return dp[i][j];

    //compute
    int max_side = 1+ min({rec(i,j-1),rec(i-1,j),rec(i-1,j-1)});

    if(grid[i][j]==0) return 0;

    //save and return
    return dp[i][j] = max_side;

}
void solver(){
    cin>>n>>m;

    grid.resize(n+1,vector<int>(m+1));
    dp.resize(n+1,vector<int>(m+1,-1));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

   int side=0;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        side= max(side,rec(i,j));
    }
   }

   cout<<(side)*(side)<<'\n';

   //cleared the gobally declarations for the next test case
   dp.clear();
   grid.clear(); 
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) solver();
    return 0;
}
 
