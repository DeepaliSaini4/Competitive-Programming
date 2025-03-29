//Given an array of N integers, find the length of the smallest sub-array that contains all the distinct elements of the array.

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];
        set<int> s;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            s.insert(arr[i]);
        }

        int distinct_cnt = s.size();  

        map<int, int> freq;
        int ans = 1e9;
        int cnt = 0;
        int head = -1, tail = 0;

        while (tail < n) {
            while (head + 1 < n && cnt < distinct_cnt) { 
                head++;
                freq[arr[head]]++;
                if (freq[arr[head]] == 1)
                    cnt++;
            }

            if (cnt == distinct_cnt) 
                ans = min(ans, head - tail + 1);

            if (tail > head) {  
                tail++;
                head = tail - 1;
            } else {  
                freq[arr[tail]]--;
                if (freq[arr[tail]] == 0)
                    cnt--;
                tail++;
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
