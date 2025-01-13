/*
Q --> Description
Given a grid of size n*m, you need to find the total number of different paths from (1, 1) to (n, m). You are allowed to move from (x, y) to (x+1, y) and (x, y) to (x, y+1). The grid may have some blocked cells, represented by 1, and it is not allowed to move to a blocked cell. An empty cell is represented by 0. You are also given an integer k and you can convert at most k blocked cells into unblocked cells.

Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains three space-separated integers n, m, k - the size of the grid and the number of cells you can convert.

Each of the following n lines contains m space-separated integers, aij - the number at that cell.

Output Format
For each test case, print the number of paths modulo 10^9 + 7.

Constraints
1 ≤ t ≤ 105

1 ≤ n, m ≤ 200

0 ≤ k ≤ 400
0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m*k over all test cases does not exceed 108.

Sample Input 1
3
3 3 2
0 1 1
1 1 0
1 0 0
3 3 1
0 1 1
1 1 0
1 0 0
2 3 0
1 0 0
0 1 0
Sample Output 1
6
0
0
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
int mod = 1e9+7;
int n,m,k;
vector<vector<int>>grid;
vector<vector<vector<int>>>dp;

int rec(int i,int j,int k){//returns the number of paths to reach (i,j) cell by removing atmost k blocks from the path
    //pruning
    if(k<0) return 0;
    //base case

    if(i==0 && j==0){
        if(grid[i][j]==1 && k==0) return 0;
        return 1;
    }

    //cache check
    if(dp[i][j][k]!=-1) return dp[i][j][k];

    //compute
    int paths =0;
    if(i-1 >= 0 && j>=0) paths += rec(i-1,j,k-grid[i][j]);
    if(j-1 >=0 && i>=0 ) paths += rec(i,j-1,k-grid[i][j]);
    //save and return
    return dp[i][j][k] = (paths%mod);

}
void solver(){

    cin>>n>>m>>k;
    grid.resize(n,vector<int>(m));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    dp.assign(n,vector<vector<int>>(m,vector<int>(k+1,-1)));

   cout<<((((rec(n-1,m-1,k))%mod)+mod)%mod)<<'\n';//returns the number of paths to reach n-1,m-1 cell removing  atmost k blocked cells

   //clearing the globally declared ds for next tc
   grid.clear();
   dp.clear();

}
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin>>t;

    while(t--) solver();
    return 0;

}

//DEBUG: TLE happened because static arrays with memset initialize the entire array, wasting time and memory.
//Dynamic vectors only allocate and initialize needed portions, making them faster and more efficient.

