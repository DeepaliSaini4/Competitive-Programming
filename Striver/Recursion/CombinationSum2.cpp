class Solution {
public:
     void rec(vector<vector<int>>&ans,vector<int>level,int sum,vector<int>&c,int target,int i){
        if(sum!=target && i==c.size()) return;
        if(sum > target) return;
        if(sum == target){
            sort(level.begin(),level.end());
            ans.push_back(level);
            return;
        }
        //2 ways
        for(int j=i;j<c.size();j++){
            if(j>i && c[j]==c[j-1]) continue;
            //take and stay
            level.push_back(c[j]);
            rec(ans,level,sum+c[j],c,target,j+1);
            //dont take and move on
            level.pop_back();
        }

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>level;
        rec(ans,level,0,candidates,target,0);
        return ans;
    }
};
//O(2^n × k)
