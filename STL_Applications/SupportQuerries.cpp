/*
Description
Design a Data Structure which can support the following queries:

1 x: Add x in structure
2 x: Remove x from the structure if present in the structure. If x doesn't present in the structure, do nothing. 
If there are multiple occurrences of x, delete only one occurrence of x.
3 ?: Print the minimum number present in the structure. If the structure is empty, print -1.
4 ?: Print the maximum number present in the structure. If the structure is empty, print -1.
5 ?: Print the sum of all numbers present in the structure. If the structure is empty, print 0.

Initially, the structure is empty.
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct ds {
    int curr_sum = 0;
    map<int, int> mp;

    void addx(int x) {
        curr_sum += x;
        mp[x]++;
    }

    void remove(int x) {
        if (mp.find(x) != mp.end()) {
            curr_sum -= x;
            mp[x]--;
            if (mp[x] == 0) mp.erase(x);
        }
    }

    void printmin() {
        if (!mp.empty()) {
            cout << mp.begin()->first << '\n';  
        } else {
            cout << "-1\n";  
        }
    }

    void printmax() {
        if (!mp.empty()) {
            cout << mp.rbegin()->first << '\n';  
        } else {
            cout << "-1\n";  
        }
    }

    void printsum() {
        cout << curr_sum << '\n';
    }
};

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    ds ad;  

    while (q--) {
        int x, t;
        char y;
        cin >> t;

        if (t == 1) {
            cin >> x;
            ad.addx(x);
        } else if (t == 2) {
            cin >> x;
            ad.remove(x);
        } else if (t == 3) {
            cin>>y;
            ad.printmin();
        } else if (t == 4) {
            cin>>y;
            ad.printmax();
        } else {
            cin>>y;
            ad.printsum();  
        }
    }
    return 0;
}
