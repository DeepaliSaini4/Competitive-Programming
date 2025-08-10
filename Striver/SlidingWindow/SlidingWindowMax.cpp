#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int head = 0;                 // current index i
        int tail = 0;                 // left boundary = head - k + 1
        int n = nums.size();
        deque<int> dq;                // store indices; values in decreasing order
        vector<int> ans;

        for (head = 0; head < n; head++) {
            // 1) Clean back: throw away smaller/equal values (they can't be future max)
            while (!dq.empty() && nums[dq.back()] <= nums[head]) dq.pop_back();

            // 2) Push current index
            dq.push_back(head);

            // 3) Maintain window size k (pop front if it slid out)
            tail = head - k + 1;
            if (!dq.empty() && dq.front() < tail) dq.pop_front();

            // 4) Record answer once first window is formed
            if (head >= k - 1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};

//DEQUE IMPLEMENTATION - O(N)
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque <int> dq;
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {

            while (!dq.empty() &&  nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            if(i-k>=0 && i-k==dq.front()) dq.pop_front();

            if (i >= k-1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
