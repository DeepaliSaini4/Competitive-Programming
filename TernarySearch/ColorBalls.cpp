/*
Description
You are given N balls and an integer K. The color of each ball is given in an array A. A basket is filled if it contains at least K balls of different colors. Find the maximum number of filled baskets you can get 
if you optimally put the balls in the baskets.

Input Format
The first line contains T, the number of test cases (1<=T<=100000).

The first line contains three space-separated integers N, K where 1<=N<=10^5, 1<=K<=N.

Next line contains N space-separated integers (0<=Ai<=1e9).

Sum of N across all test cases <=10^6.

Output Format
For each test case output the maximum number of filled baskets in a new line. 

Sample Input 1
3
5 5
1 2 3 4 5
5 2
1 2 3 4 5
6 3
1 2 2 1 3 3

Sample Output 1
1
2
2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100001;
ll n, k;
ll arr[N];
map<ll, ll> freq;

bool check(ll minVal) {
    ll totalUsefulBalls = 0;
    for (auto &v : freq) {  // Efficient map iteration by reference
        totalUsefulBalls += min(v.second, minVal);
    }
    return totalUsefulBalls >= k * minVal;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll testcases;
    cin >> testcases;

    while (testcases--) {
        cin >> n >> k;
        freq.clear();  // Ensure the map is cleared for each test case

        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        ll low = 0, high = n;
        ll ans = 0;  // Fix initial answer to `0`

        while (low <= high) {
            ll mid = (low + high) / 2;
            if (check(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
