/*
Description
You are climbing a staircase. It takes 
N steps to reach the top.

Each time you can either climb 
1 or 
M steps. What is the minimum number of climbs you need to do to reach the top, i.e., 
Nth stair?

Input Format
The first line of input contains 
T - the number of test cases. Then 
T test cases follow.
The only line of each test case contains two space-separated integers - 
N and 
M.

Output Format
For each test case, print the minimum number of climbs require to climb the top on a new line.

Constraints

1≤T≤10 

1≤M≤N≤10^9 --> HERE DP CANT BE USED TO STORE VALUES AS CONSTRAINT VALUES ARE TOO HIGH!

Sample Input 1
2
5 1
6 4

Sample Output 1
5
3
 
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while (t--)
        {
            int n, m; 

            cin >> n >> m;
            cout << n / m + n % m <<"\n";
        }

    return 0;
}
