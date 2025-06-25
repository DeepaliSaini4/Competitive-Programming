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

int dfstree(TreeNode*root){
    if(root==NULL) return 0;
    
    int left = dfstree(root->left);
    if(left==-1) return -1;
    
    int right = dfstree(root->right);
    if(right==-1) return -1;
    
    if(abs(left-right)>1) return -1;
    
    return max(left,right)+1;
}

bool isbalanced(TreeNode* root){
    if(root == NULL) return true;
    else return !(dfstree(root)==-1);
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
    if(isbalanced(root)){
        cout<<"Height of the balanced bst is: "<<dfstree(root)<<'\n';
    }
    else{
        cout<<"The tree is not balanced. "<<'\n';
    }
    return 0;
}
