/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

// Note: In a BST, it's not enough to compare a node with its immediate children — you must ensure all nodes in the
//left subtree < root->val and all nodes in the right subtree > root->val.
class Solution {
public:
    bool helper(TreeNode* root, long minval, long maxval) {
        if (!root)
            return true;

        if (root->val >= maxval || root->val <= minval)
            return false;

        return helper(root->left, minval, root->val) &&
               helper(root->right, root->val, maxval);
    }
    bool isValidBST(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }
};

