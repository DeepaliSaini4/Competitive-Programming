/*
Given a binary array nums, you should delete one element from it.
Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int tail = 0;
        int head = -1;
        int n = nums.size();
        bool del = 0;
        int ans = 0;
        int maxlen = 0;

        while (tail < n) {
            while (head + 1 < n) {
                if (nums[head+1] == 0) {
                   if(!del) del = 1;
                   else{
                    break;
                   }
                }
                   head++;
            }
            ans = head - tail +1  ;
            maxlen = max(ans, maxlen);
            if (head < tail) {
                tail++;
                head = tail - 1;
            } else {
                if (nums[tail] == 0) {
                    del = 0;
                }
                tail++;
            }
        }
        return maxlen - 1; 
    }
};
