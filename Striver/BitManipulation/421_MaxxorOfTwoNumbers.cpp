/*Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.*/
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int ans = 0;
        int mask = 0;
        for(int b=31;b>=0;b--){
            mask|=(1<<b);//turning on all the bits till 'b'
            unordered_set<int>pref;
            pref.reserve(nums.size()*2);

            for(int x:nums) pref.insert(x & mask);

            int cand = ans | (1<<b);
            bool ok = false;
            for(int p:pref){
                if(pref.count(p^cand)){ok = true;break;}
            }
            if(ok) ans = cand;
        }
        return ans;
    }
};
