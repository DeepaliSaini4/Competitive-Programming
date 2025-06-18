#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
    
};

void LevelOrderTraversal(TreeNode* root){
    if(root==NULL) return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    
    //constructing the binary tree manually
    TreeNode* root = new TreeNode(10);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(18);
	root->right->left = new TreeNode(14);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(6);
	
	LevelOrderTraversal(root);
    return 0;
}
