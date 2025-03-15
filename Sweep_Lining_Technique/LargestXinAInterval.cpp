/*
Q -> find the largest X out of all the segments that cover the point y.
given n intervals [Li,Ri]
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define F first
#define S second

void solver() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> events;
    
    for (int i = 0; i < n; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        events.push_back({l, {0, x}}); // Start of an interval
        events.push_back({r, {2, x}}); // End of an interval
    }

    int q;
    cin >> q;
    int ans[q];

    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        events.push_back({y, {1, i}}); // Query event
    }

    sort(events.begin(), events.end());
    multiset<int> mt;

    for (auto event : events) {
        if (event.S.F == 0) {
            // Start of an interval
            mt.insert(event.S.S);
        } else if (event.S.F == 2) {
            // End of an interval
            mt.erase(mt.find(event.S.S));
        } else {
            // Query event (Find max X covering y)
            if (mt.empty()) {
                ans[event.S.S] = 0;
            } else {
                ans[event.S.S] = *mt.rbegin();
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solver();

    return 0;
}
