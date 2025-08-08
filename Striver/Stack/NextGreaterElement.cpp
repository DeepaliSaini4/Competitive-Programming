class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        vector<int> nextgreater(nums2.size());
        nextgreater[nums2.size() - 1] = -1;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            if (s.empty()) {
                nextgreater[i] = -1;
                s.push(nums2[i]);
            } else {
                while (!s.empty() && s.top() <= nums2[i]) {
                    s.pop();
                }
                if (s.empty()) {
                    nextgreater[i] = -1;
                    s.push(nums2[i]);
                } else {
                    nextgreater[i] = s.top();
                    s.push(nums2[i]);
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    ans.push_back(nextgreater[j]);
                }
            }
        }
        return ans;
    }
};
