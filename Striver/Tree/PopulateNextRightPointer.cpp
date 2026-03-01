/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
You are given the root of a perfect binary tree (all levels fully filled).
You must connect each node’s next pointer to its next right node in the same level.
If there is no next right node, set next = NULL.
Return the root after connecting all next pointers.
*/

class Solution {
public:
    void helper(Node* root){
        if(!root->left && !root->right) return;//leave node condition over here
        root->left->next = root->right;
        if(root->next)
        root->right->next = root->next->left;
       else  root->right->next = nullptr;
       helper(root->left);
       helper(root->right);
    }
    Node* connect(Node* root) {
        if(!root) return root;
        helper(root);
        return root;
    }
};
