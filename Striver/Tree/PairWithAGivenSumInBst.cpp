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
 Given the root of a Binary Search Tree and an integer k,
determine if there exist two different nodes in the tree such that:

node1->val + node2->val == k

Return true if such a pair exists, otherwise return false.
 */
 #include<bits/stdc++.h>
class Solution {
public:

    bool helper(TreeNode* root,int k,unordered_set<int> &seter){
        if(!root) return false;
        if(seter.find(k-root->val)!=seter.end())
        return true;
        seter.insert(root->val);
        return (helper(root->left,k,seter) || helper(root->right,k,seter));
    }

    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> setmeup;
        return helper(root,k,setmeup);

    }
};
