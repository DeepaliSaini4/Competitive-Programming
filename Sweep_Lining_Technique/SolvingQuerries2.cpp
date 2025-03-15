#include <bits/stdc++.h>
using namespace std;

#define int long long 

using event = pair<pair<int,int>,pair<int,int>>; // each event has 4 values
#define F first
#define S second

/*
    0 -> start
    1 -> Query
    2 -> end
*/

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    vector<event> events;
    multiset<int> mt;
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        events.push_back({{l, 0}, {x, i}});
        events.push_back({{r, 2}, {x, i}});
    }
    
    sort(events.begin(), events.end());
    vector<pair<int, vector<int>>> savedvalues;
    
    for (auto v : events) {
        if (v.F.S == 0) {
            // Beginning of an interval 
            mt.insert(v.S.F);
        } else if (v.F.S == 2) {
            // End of an interval
            mt.erase(mt.find(v.S.F));
        }
        
        vector<int> temp;
        int cnt = 0;
        for (auto it = mt.rbegin(); it != mt.rend(); it++) {
            temp.push_back(*it);
            cnt++;
            if (cnt == 10) break;
        }
        savedvalues.push_back({v.F.F, temp});
    }
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        
        vector<int> ans;
        for (auto &sv : savedvalues) {
            if (sv.F > y) break;
            ans = sv.S;
        }
        
        for (auto v : ans) {
            cout << v << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
