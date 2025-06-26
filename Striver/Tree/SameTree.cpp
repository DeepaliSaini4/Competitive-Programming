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
    bool helper(TreeNode* p, TreeNode* q){
        if(p== NULL && q == NULL) return true;

        if(p==NULL || q== NULL) return false;
        //check if left is same 
        
        if(!helper(p->left,q->left)) return false;
        //check if right os same
        else if(!helper(p->right,q->right)) return false;
        else return p->val == q->val;
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p,q);
    }
};
