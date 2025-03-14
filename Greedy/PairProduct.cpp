/*
Description
You have given an array of n numbers and a positive integer m. Lets define c(i, j) = |ai - aj|.
Your task is to find the product of c(i, j) for all 1 ≤ i < j ≤ n. Since this product can be very large, print it with modulo m.

Input Format
The first line contains two integers n, m (2 ≤ n ≤ 2 x 105, 1 ≤ m ≤ 1000) — number of numbers and modulo.
The second line contains n integers a1, a2, …, an (0 ≤ ai ≤ 109).

Output Format
Output a single integer.

Sample Input 1
2 10
8 5

Sample Output 1
3

Sample Input 2
3 12
1 4 5

Sample Output 2
0
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // If n > m, answer is 0(Pigeonhole Principle)
    if (n > m) {
        cout << 0 << "\n";
        return 0;
    }

    int product = 1;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {  // Ensure i < j
            product = (product * abs(arr[i] - arr[j]) % m) % m;
        }
    }

    cout << product << "\n";
    return 0;
}
