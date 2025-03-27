/*
Given two numbers K and S. Determine how many different values of X, Y, and Z such that (0≤X,Y,Z≤K) and X+Y+Z=S.

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int K, S;
    cin >> K >> S;

    int count = 0;
    
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int z = S - (x + y);
            if (z >= 0 && z <= K) {
                count++;
            }
        }
    }

    cout << count << "\n";
}
