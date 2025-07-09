/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //returns the root of the tree formed by splititng the array from rught to left
    TreeNode* helper( int right, int left, vector<int>&nums){
        if(right<left) return nullptr;
        
        int mid = (right+left)/2;
        TreeNode* root = new TreeNode (nums[mid]);

        root->left = helper(mid-1,left,nums);
        root->right = helper(right,mid+1,nums);

        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        return helper(nums.size()-1,0,nums);
    }
};
