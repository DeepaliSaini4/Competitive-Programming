/*
Description
There are n light bulbs in a row. Each bulb is either on or off given in input as 1 or 0 respectively.

In one operation you can select any k consecutive bulbs and flip their switches, that is, if a bulb was off it becomes on and vice versa.

Find minimum number of operations to turn all the bulbs on. If it's impossible to do so print -1.

Input Format
First line of input contains T, number of test cases.
First line of each test case contains n and k.
Second line contains n integers, ith integer si represents the state of the ith bulb.


Output Format
For each testcase if its possible to turn all the bulbs on, print the minimum operations required, else print -1

Sample Input 1
1
5 1
0 1 0 1 1
Sample Output 1
2
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> bulb(n);

        bool zero_present = false; // To check if there is at least one '0'
        for (int i = 0; i < n; i++) {
            cin >> bulb[i];
            if (bulb[i] == 0) zero_present = true;
        }

        // Edge case: If k == 0, we can't flip anything.
        if (k == 0) {
            cout << (zero_present ? -1 : 0) << '\n';
            continue;
        }

        int op_num = 0; // Count of operations
        for (int i = 0; i <= n - k; i++) { 
            if (bulb[i] == 0) { // If bulb is OFF, flip k bulbs starting from i
                op_num++;
                // Flip k bulbs
                for (int j = 0; j < k; j++) {
                    bulb[i + j] ^= 1; // Flip operation (XOR with 1)
                }
            }
        }

        // Check if all bulbs are ON
        bool all_on = true;
        for (int i = 0; i < n; i++) {
            if (bulb[i] == 0) {
                all_on = false;
                break;
            }
        }

        if (all_on)
            cout << op_num << '\n'; // Print minimum flips needed
        else
            cout << -1 << '\n'; // If not possible
    }
    
    return 0;
}
