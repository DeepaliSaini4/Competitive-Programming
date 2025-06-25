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

//traverse the 
TreeNode* LowestCommonAncestor(TreeNode*root,int p,int q){
    if(root == NULL || root->data==p || root->data ==q){
        return root;
    }
    TreeNode* left = LowestCommonAncestor(root->left,p,q);
    TreeNode* right = LowestCommonAncestor(root->right,p,q);
    if(left == NULL) return right;
    else if(right == NULL) return left;
    else return root;
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
    
    TreeNode* lca = LowestCommonAncestor(root,18,14);
    
    cout<<"The lca is given as: "<<lca->data<<'\n';

    return 0;
}
