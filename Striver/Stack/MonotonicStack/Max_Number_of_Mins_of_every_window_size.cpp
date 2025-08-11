#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxOfMin(vector<int>& arr) {
        int n = (int)arr.size();
        if (n == 0) return {};
        vector<int> left(n), right(n), ans(n, INT_MIN);
        stack<int> st;
        
        //prev smaller element
        for(int i=0;i<n;i++){
            while(!s.empty() && s.top()>=arr[i]) s.pop();
            left[i] = s.empty() ? -1: s.top();
            s.push(i);
        }
        
        while (!st.empty()) st.pop();
        //next smaller element
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && s.top()>=arr[i])s.pop();
            right[i] = s.empty() ? n:s.top();
            s.push(i);
        }
        
        for(int i=0;i<n;i++){
            int len = right[i] - left[i] - 1;
            ans[len - 1] = max(ans[len-1],arr[i]);
        }
        
        for(int k= n-2;k>=0;k--){
            ans[k] = max(ans[k],ans[k+1]);
        }
        return ans;
    }
};
