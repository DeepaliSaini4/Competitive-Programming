//Given a Binary Tree, convert the value of its nodes to follow the Children Sum Property. The Children Sum Property in a binary tree states that for every node,
//the sum of its children's values (if they exist) should be equal to the node's value. If a child is missing, it is considered as having a value of 0.

//constraint can only increase the values of nodes not decrease
#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data){
        this-> val = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

//childrensumproperty
void childsumprop(TreeNode* root){
    if(!root || (!root->left && !root->right)) return;
    int leftsum = (root->left)? root->left->val : 0;
    int righttsum = (root->right)? root->right->val : 0;
    int childsum = righttsum+leftsum;
    if(root->val<childsum){
        root->val= childsum;
    }else{
        if(root->left) root->left->val = root->val;
        else if(root->right) root->right->val = root->val;
    }
    childsumprop(root->left);
    childsumprop(root->right);
    int tot = 0;
    if(root->left) tot+=root->left->val;
    if(root->right) tot+=root->right->val;
    if(root->left || root->right) root->val = tot;
    
}

void print(TreeNode* root){
    if(!root) return;
    print(root->left);
    print(root->right);
    cout<<root->val<<" ";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    //manual creation of bst
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->left->left = new TreeNode(2);
    root->right = new TreeNode(30);
    root->right->right = new TreeNode(36);
    root->left->right = new TreeNode(18);
    root->right->left = new TreeNode(24);
    
    print(root);
    cout<<"\n";
    
    childsumprop(root);
    
    print(root);
    
    return 0;
}
