#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElements(const vector<int>& arr) {
        int n = arr.size();
        vector<int> nxt(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() >= arr[i])
                st.pop();                      // remove all ≥ current

            nxt[i] = st.empty() ? -1 : st.top(); // next smaller or -1
            st.push(arr[i]);                     // add current for left elems
        }
        return nxt;
    }
};
