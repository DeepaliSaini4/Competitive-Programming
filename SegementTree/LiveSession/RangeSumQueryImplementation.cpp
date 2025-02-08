#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int A[N];
int tree[4 * N];

// Build the segment tree
void build(int node, int start, int end) {
    if (start == end) {
        tree[node] = A[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Update the value at index i to x
void update(int node, int start, int end, int i, int x) {
    if (start == end) {
        A[i] = x;
        tree[node] = x;
        return;
    }
    int mid = (start + end) / 2;
    if (i <= mid) {
        update(2 * node, start, mid, i, x);
    } else {
        update(2 * node + 1, mid + 1, end, i, x);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

// Query the sum in range [lq, rq]
int query(int node, int start, int end, int lq, int rq) {
    if (lq > end || start > rq) {
        // No intersection
        return 0;
    }
    if (start >= lq && end <= rq) {
        // Fully inside the query range
        return tree[node];
    }
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, lq, rq) + query(2 * node + 1, mid + 1, end, lq, rq);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    build(1, 0, n - 1);

    int q;
    cin >> q;  // Number of queries
    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            // Update operation
            int i, x;
            cin >> i >> x;
            update(1, 0, n - 1, i, x);
        } else if (type == 2) {
            // Query operation
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << "\n";
        }
    }

    return 0;
}
