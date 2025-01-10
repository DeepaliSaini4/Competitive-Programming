/*
Q -> Given an array of size N, and Q queries, for each query, you need to get the indices of the elements of the array whose subset-sum is equal to the queried sum 
sum i , if possible, else return −1.
Complete the Function subset_queries( vector &arr, vector &queries ) that takes vector 
a and queries vector as input.
*/
#include <bits/stdc++.h>
using namespace std;


#define ll int64_t

vector<vector<int>> ans;
vector<vector<int>> dp;

int rec(int level, int left, vector<int> &arr) {
    // pruning
    if(left < 0) return 0;

    // base case 
    if(level == arr.size()) {
        return (left == 0);
    }

    // cache check
    if(dp[level][left] != -1) return dp[level][left];

    // transition
    int res = rec(level+1, left, arr) || rec(level+1, left-arr[level], arr);

    // save and return
    return dp[level][left]=res;
}

void printset(int level, int left, vector<int> &arr, vector<int> &ansOfQuery) {
    // base case
    if(level == arr.size()) {
        return;
    }

    // find the correct transition
    if(rec(level+1, left, arr)) {    // don't take
        printset(level+1, left, arr, ansOfQuery);
    } else if(rec(level+1, left-arr[level], arr)) {    // take
        ansOfQuery.push_back(level);
        printset(level+1, left-arr[level], arr, ansOfQuery);
    }
}

vector<vector<int>> subset_queries(vector<int> &arr, vector<int> &queries) {
    dp.assign(105, vector<int> (100100, -1));

    for(auto query_sum:queries) {
        vector<int> ansOfQuery;

        if(rec(0, query_sum, arr)) {
            printset(0, query_sum, arr, ansOfQuery);
        } else {
            ansOfQuery.push_back(-1);
        }

        ans.push_back(ansOfQuery);
    }

    return ans;
}


void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)cin >> arr[i];
    vector<int> queries(Q);
    for (int i = 0; i < Q; i++)cin >> queries[i];
    auto ans = subset_queries(arr, queries);

    // checker.
    if (ans.size() != Q) {
        cout << 101 << endl;
        return;
    }
    for (int i = 0; i < Q; i++) {
        auto x = ans[i];
        if (x.size() == 0) {
            cout << 101 << endl;
            continue;
        }
        if (x.size() == 1 && x[0] == -1) {
            cout << -1 << endl;
            continue;
        }
        ll sum = 0, p = -10;
        for (auto y : x) {
            if (y < 0 || y >= N || p >= y ) { // valid 0-indexed.
                sum = -1111;
                break;
            }
            p = y;
            sum += arr[y];
        }
        if (sum == queries[i]) {
            cout << 1 << endl;
        }
        else cout << 101 << endl;
    }
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(nullptr); cout.tie(nullptr);

#ifdef Mastermind_
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // int i = 1;
    // cin >> t;
    while (t--) {
        // cout << "Case #" << i << ": ";
        solve();
        // i++;
    }
    return 0;
}
