#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
  int data;
  TreeNode* right;
  TreeNode* left;
  TreeNode(int data){
      this->data = data;
      this-> left = NULL;
      this -> right = NULL;
  }
};

void LeftBoundary(TreeNode*root,vector<int>&lefti){
    if(root==NULL) return;
    if(!(root->right == NULL && root->left == NULL) )
    lefti.push_back(root->data);
    if(root->left) LeftBoundary(root->left,lefti);
    else if(root->right) LeftBoundary(root->right,lefti);
}

void RightBoundary(TreeNode*root,vector<int>&righti){
    if(root==NULL) return;
    if(!(root->right==NULL && root->left ==NULL) )
    righti.push_back(root->data);
    if(root->right) RightBoundary(root->right,righti);
    else if(root->left) RightBoundary(root->left,righti);
}
void leavenodes(TreeNode* root,vector<int>&leaf){
    if(root ==NULL) return;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left == NULL && curr->right == NULL) {
            leaf.push_back(curr->data);
        }
        else{
            if(curr->left)q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    //manually coinstructing a Tree
    TreeNode* root = new TreeNode(18);
    root->right = new TreeNode(45);
    root->left = new TreeNode(11);
    root->right->left = new TreeNode(20);
    root->right->right = new TreeNode(67);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(14);
    
    //boundary traversals
    vector<int>lefti;
    LeftBoundary(root->left,lefti);
    vector<int>leaf;
    leavenodes(root,leaf);
    vector<int>righti;
    RightBoundary(root->right,righti);
    
    cout<<root->data<<" ";
    
    for(auto it:lefti){
        cout<<it<<" ";
    }
    for(auto it:leaf){
        cout<<it<<" ";
    }
   reverse(righti.begin(),righti.end());
    for(auto it:righti){
        cout<<it<<" ";
    }
       return 0;
     
}
