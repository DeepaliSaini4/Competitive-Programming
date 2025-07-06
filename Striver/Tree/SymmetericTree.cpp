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
    bool canmatch(TreeNode* root1, TreeNode* root2){
        if(root1->left == NULL && root2->right ==NULL) return true;
        if(root1->left->val == root2->right->val) return true;
        if(root1->left == NULL || root2->right ==NULL) return false;
        bool leftcheck = canmatch(root1->left,root2->right);
        bool rightcheck = canmatch(root1->right,root2->left);
        return (leftcheck && rightcheck);
    }
    bool isSymmetric(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;
        else if (root->left == NULL || root->right == NULL) return false;
        return canmatch(root->left,root->right);
    }
};
