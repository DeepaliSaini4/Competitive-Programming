/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

A subarray is a contiguous non-empty sequence of elements within an array.

*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        int sum = 0;
        int n = nums.size();
        mymap[0] = 1;
        int cnt = 0;
        for(int i=0;i<n;i++) {
            sum+=nums[i];
            int rem = sum-k;
            cnt+=mymap[rem];
            mymap[sum]++;
        }
        return cnt;
    }
};
