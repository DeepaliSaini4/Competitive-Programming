/*
Q -> Description
Given a grid of size **n x m with integers, you need to find the maximum sum Subgrid.

Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.
The first line of each test case contains two space-separated integers n, m - the size of the grid.
Each of the next n lines contains m space-separated integers, a[i][j] - the number at the cell (i, j).

Output Format
For each test case, print the maximum sum.

Constraints
1 ≤ t ≤ 105
1 ≤ n, m ≤ 105
-105 ≤ a[i][j] ≤ 105

It is guaranteed that the sum of n x m over all test cases does not exceed 105.

Sample Input 1
3
2 3
10 2 -1
-4 5 -1
2 2
-1 -1
-1 -1
2 2
1 2
3 4

Sample Output 1
13
-1
10
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<vector<int>>grid;
int n,m;

//kadane's algorithm
int getbestsubarraysum(vector<int>arr){
    if(arr.empty()){
        return 0;
    }

    int currsum = arr[0], maxsum = arr[0];
    for(int i=1;i<arr.size();i++){
        //for each element decide whether to add it to the existing sum or start a new subarray with the current element
        currsum = max(currsum+arr[i],arr[i]);
        maxsum = max(currsum,maxsum);
    } 
    return maxsum;
}

void solve(){
    int n,m;
    cin>>n>>m;
    grid.resize(n);
    for(int i=0;i<n;i++){
        grid[i].resize(m);
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    int ans = -2e18; // -2 quintillion
    if(m<n){
         for(int c1=0;c1<m;c1++){
             vector<int>rowsum(n,0);//to maintain current wise row chunk sum
             for(int c2=c1;c2<m;c2++){
                //add ne column to all the rows
                 for(int r=0;r<n;r++){
                     rowsum[r] += grid[r][c2];
                 }
                 ans = max(ans,getbestsubarraysum(rowsum));
             }
        }
    }
    else{
        for(int r1=0; r1<n; r1++){
            vector<int>col_sum(m,0);
            for(int r2=r1;r2<n;r2++){
                //add new col to all rows
                for(int c=0;c<m;c++){
                    col_sum[c] +=grid[r2][c];
                }
                ans = max(ans,getbestsubarraysum(col_sum));
            }
        }

    }
