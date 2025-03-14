/*
Description
Input Format
The first line contains a single integer T - the number of test cases. Each test case consists of a single line containing two integers N and K.

Output Format
For each test case, output the number of different permutations consisting of numbers from 1 to N such that there are exactly K inverse pairs modulo 10^9+7.

Constraints
1≤T≤10^6

1≤N≤1000 

0≤K≤1000

Sample Input 1
4
3 1
1 0
4 4
3 4

Sample Output 1
2
1
5
0
*/
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int dp[1001][1001];

void precompute() {
    dp[1][0] = 1;

    for (int i = 2; i <= 1000; ++i) {
        vector<int> prefix(1001, 0);
        prefix[0] = dp[i - 1][0];

        for (int k = 1; k <= 1000; ++k) {
            prefix[k] = (prefix[k - 1] + dp[i - 1][k]) % MOD;
        }
 
        for (int k = 0; k <= 1000; ++k) {
            dp[i][k] = prefix[k];
            if (k >= i) {
                dp[i][k] = (dp[i][k] - prefix[k - i] + MOD) % MOD;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;
        cout << dp[N][K] << "\n";
    }
    
    return 0;
}
