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

int HeightOfTree(TreeNode* root){
    if(root==NULL) return 0;
    int rh =  HeightOfTree(root->right);
    int left = HeightOfTree(root->left);
    return (max(left,rh)+1);
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
    cout<<"Height/depth of the tree is: "<<HeightOfTree(root)<<'\n';
	

}
