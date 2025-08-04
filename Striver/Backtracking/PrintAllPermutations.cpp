class Solution {
public:
    void generator(vector<vector<int>>&ans,vector<int>nums,int idx){
        //base case
        if(idx == nums.size()){
            ans.push_back(nums);//this step takes o(n) time
            return;
        }
        for(int i = idx;i<nums.size();i++){
            swap(nums[i],nums[idx]);
            generator(ans,nums,idx+1);// we have n! permutations
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        generator(ans,nums,0);
        return ans;
    }
};

//tc = O(n! * n)
