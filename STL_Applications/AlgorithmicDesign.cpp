/*
Imagine managing a database of dashboard of some firm with the following operations:

Insert: Add a new user to the server named x, with some value.

Sum: Sum of all the value of user.

Erase Entries: Remove particular user.

Get Max: Retrieve the max value of the user.

Get Distinct: No. of users with distinct value.

*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct bag {
    int curr_sum = 0;
    map<int, int> mp;

    void insert(int x) { // O(log n)
        curr_sum += x;
        mp[x]++;
    }

    void remove(int x) { // O(log n)
        if (mp.find(x) != mp.end()) {
            curr_sum -= x;
            mp[x]--;
            if (mp[x] == 0) mp.erase(x);
        }
    }

    int getmax() { // O(1)
        if (mp.empty()) return LLONG_MIN; // Handle empty case
        return mp.rbegin()->first; // rbegin() -> iterator to the last element
    }

    int sum() { // O(1)
        return curr_sum;
    }

    int getdistinct() { // O(1)
        return mp.size();
    }
};

void solve() {
    bag b;
    b.insert(5);
    b.insert(3);
    b.insert(8);
    b.insert(5);
    
    cout << "Max: " << b.getmax() << '\n'; // Should print 8
    cout << "Sum: " << b.sum() << '\n'; // Should print 21
    cout << "Distinct Count: " << b.getdistinct() << '\n'; // Should print 3

    b.remove(8);
    cout << "Max after removing 8: " << b.getmax() << '\n'; // Should print 5
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
