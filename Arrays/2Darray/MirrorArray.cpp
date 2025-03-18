/*
Given two numbers N and M and a 2D array of size N×M. For each row, print the inverted array that appears in the mirror (i.e., reverse the elements of each row).
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long 

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    int t;
    cin >> t;
    while (t--) { 
        int n, m;
        cin >> n >> m;
        int arr[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j >= 0; j--) {
                cout << arr[i][j] << " ";  
            }
            cout << '\n';
        }
    }
    return 0;
}
