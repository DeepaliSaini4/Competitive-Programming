class Solution {
public:
    void rec(vector<vector<int>>&ans,vector<int>level,int sum,vector<int>&c,int target,int i){
        if(sum!=target && i==c.size()) return;
        if(sum > target) return;
        if(sum == target){
            ans.push_back(level);
            return;
        }
        //2 ways
        //take and stay
        level.push_back(c[i]);
        rec(ans,level,sum+c[i],c,target,i);
        //dont take and move on
        level.pop_back();
        rec(ans,level,sum,c,target,i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>level;
        rec(ans,level,0,candidates,target,0);
        return ans;
    }
};
