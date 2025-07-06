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
    queue<TreeNode*>res;
    void  preordertraversal(TreeNode* root,queue<TreeNode*>&res){
        if(root == NULL) return;
        res.push(root);
        preordertraversal(root->left,res);
        preordertraversal(root->right,res);
        return;
    }
    void flatten(TreeNode* root) {
        if(!root) return;
        preordertraversal(root,res);
       while(!res.empty()){
        auto it = res.front();
        res.pop();
        it->left = NULL;
        if(!res.empty())
        it->right = res.front();
        else it->right = NULL;
       }
       return; 
    }
};
