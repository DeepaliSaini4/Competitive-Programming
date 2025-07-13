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
    int maxsum = 0;
    class info{
        public:
        int minval;
        int maxval;
        bool isbst;
        int maxsum;
    };

    info dfs(TreeNode* root){
        if(!root) return{INT_MAX,INT_MIN,true,0};
        info left = dfs(root->left);
        info right = dfs(root->right);
        //condiiton when maxsum is increemented aka updated on finding a vaild subtree that is a bst
        if(root->val>left.maxval && root->val<right.minval && right.isbst && left.isbst){
            int totalsum = right.maxsum + left.maxsum + root->val;
            maxsum = max(maxsum , totalsum);
            return {min(left.minval,root->val),max(right.maxval,root->val),true,totalsum};
        }
        return {0,0,false,0};
    }

    int maxSumBST(TreeNode* root) {
        dfs(root);
        return maxsum;
    }
};
