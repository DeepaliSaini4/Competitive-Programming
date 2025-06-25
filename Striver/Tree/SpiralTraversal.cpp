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

void SpiralTraversal(TreeNode*root){
    if(root == NULL) return;
    vector<int>sprialt;
    queue<TreeNode*>q;
    q.push(root);
    bool lefttoright = 1;
    while(!q.empty()){
        int size = q.size();//size of the current level
        vector<int>level(size);
        for(int i=0;i<size;i++){
            TreeNode* curr = q.front();
            q.pop();
            int index = lefttoright? i : size - i -1;
            level[index] = curr->data;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
            
        }
        lefttoright = !lefttoright;
        for(auto it:level) sprialt.push_back(it);//transerferring the data
    }
    for(auto it: sprialt){
        cout<<it<<" ";
    }
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
    SpiralTraversal(root);
	

}
