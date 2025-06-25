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

int height(TreeNode* root, int &dia){
    if(root == NULL) return 0;
    int left = height(root->left,dia);
    int right = height(root->right,dia);
    
    dia = max(dia,left+right);
    return max(left,right) +1;
    
}

int diameter(TreeNode* root){
    if(root == NULL) return 0;
    int dia  = 0;
    height (root,dia);
    return dia;
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
    cout<<"Dia of the tree is: "<<diameter(root)<<'\n';
    return 0;

}
