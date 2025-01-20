#include<bits/stdc++.h>
using namespace std;

#define int long long
int n, m, x;
string a, b, c;
vector<vector<vector<int>>> dp;

int rec(int i, int j, int k) {
    // Base case: If any string is exhausted
    if (i >= n || j >= m || k >= x) {
        return 0;
    }
    // Check the cache
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    // Compute the result
    int ans = 0;
    // Skip characters in `a`, `b`, or `c`
    ans = max(ans, rec(i + 1, j, k));
    ans = max(ans, rec(i, j + 1, k));
    ans = max(ans, rec(i, j, k + 1));
    // Include characters if they match
    if (a[i] == b[j] && b[j] == c[k]) {
        ans = max(ans, 1 + rec(i + 1, j + 1, k + 1));
    }
    // Store the result and return
    return dp[i][j][k] = ans;
}

void solver() {
    cin >> n >> m >> x;
    cin >> a >> b >> c;
    dp.resize(n, vector<vector<int>>(m, vector<int>(x, -1)));
    cout << rec(0, 0, 0) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solver();
    return 0;
}
