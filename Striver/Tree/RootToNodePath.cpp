#include <bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
  int data;
  TreeNode* right;
  TreeNode* left;
  TreeNode(int data){
      this->data = data;
      this->right = nullptr;
      this->left = nullptr;
  }
};

bool helper(TreeNode*root,int target,vector<int>&Arr){
    if(root == NULL) return false;
    
    Arr.push_back(root->data);
    
    if(root->data == target){
        return true;
    }
    if(helper(root->left,target,Arr)||helper(root->right,target,Arr)){
        return true;
    }
    Arr.pop_back();
    return false;
    
}

void RootToNodePath(TreeNode* root){
    if(root==nullptr) return;
    vector<int>Arr;
    int target = 18;
   if(helper(root,target,Arr)){
       for(auto it:Arr){
           cout<<it<<" ";
       }
   }
   return;
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	//manual tree creation
	TreeNode* root = new TreeNode(10);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(18);
	root->right->left = new TreeNode(14);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(6);
	
	RootToNodePath(root);
	
	
	return 0;
}
