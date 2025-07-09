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
    TreeNode* helper(vector<int>&preorder,int &index, int bound){
        if(index == preorder.size() || preorder[index]>bound) return nullptr;

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = helper(preorder,index,root->val);
        root->right = helper(preorder,index,bound);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.empty()) return nullptr;
        int index = 0;
        return helper(preorder,index, INT_MAX);
    }
};
