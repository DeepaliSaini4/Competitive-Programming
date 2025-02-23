/*
Description
Given two numbers X and Y. Print the sum of all odd numbers between them, excluding X and Y.

Input Format
First line contains a number T, the number of test cases.

Next T lines will contain two numbers X and Y.

Output Format
Print the sum of all odd numbers between X and Y.
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
        int X, Y;
        cin >> X >> Y;

        if (X > Y) swap(X, Y);  // Ensure X < Y

        // Adjust X+1 to the first odd number strictly inside (X, Y)
        X += 1;
        if (X % 2 == 0) X += 1;

        // Adjust Y-1 to the last odd number strictly inside (X, Y)
        Y -= 1;
        if (Y % 2 == 0) Y -= 1;

        // If no valid range exists
        if (X > Y) {
            cout << "0\n";
            continue;
        }

        // Number of odd numbers in the range
        int n = ((Y - X) / 2) + 1;

        // Sum of arithmetic sequence: (first + last) * count / 2
        int sum = (n * (X + Y)) / 2;

        cout << sum << '\n';
    }

    return 0;
}
