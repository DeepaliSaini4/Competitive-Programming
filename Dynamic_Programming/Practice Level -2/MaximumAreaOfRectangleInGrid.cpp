/*
Q ->Description
Given a grid of size n*m with 0s and 1s, you need to find the area of the largest rectangle containing only 1.

Input Format
The first line of the input contains one integer t - the number of test cases. Then t test cases follow.

The first line of each test case contains two space-separated integers n, m - the size of the grid.

Each of the next n lines contains m space-separated integers, aij - the number at that cell.

Output Format
For each test case, print the maximum area.

Constraints
1 ≤ t ≤ 105

1 ≤ n, m ≤ 200

0 ≤ aij ≤ 1

It is guaranteed that the sum of n*m over all test cases does not exceed 105.

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
2
4
0
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
   ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int t;
   cin >> t;
   while(t--) {
       int n, m;
       cin >> n >> m;
       bool grid[n][m];
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               cin >> grid[i][j];
           }
       }
       int dp[n][m];
       memset(dp, 0, sizeof(dp));
       int ans = 0;
       for (int i = 0; i < n; ++i) {
           for (int j = 0; j < m; ++j) {
               if(grid[i][j]) {
                   dp[i][j] = j == 0 ? 1 : dp[i][j-1] + 1;
                   int width = dp[i][j];
                   
                   for (int k = i; k >= 0; --k) {
                       width = min(width, dp[k][j]);
                       ans = max(ans, width * (i - k + 1));
                   }
               }
           }
       }
       cout << ans << "\n";
   }
   return 0;
}
