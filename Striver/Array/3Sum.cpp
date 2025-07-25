class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i=0;i<=nums.size()-3;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int sum = -nums[i];
            int k = n-1;
            int j = i+1;
            while(j<k){
            int summade = nums[j] + nums[k];
            if(summade==sum){
                vector<int>ans1;
                ans1.push_back(nums[i]);
                ans1.push_back(nums[j]);
                ans1.push_back(nums[k]);
                ans.push_back(ans1);
                j++;k--;
                while(j<k && nums[j]==nums[j-1])j++;
                while(j<k && nums[k]==nums[k+1])k--;
            }else if (summade>sum){
                k--;
            }else{
                j++;
            }}
        }
        return ans;
    }
};
