//levelwise max width -> max number of nodes in a level (nodes can be hypothetical as well for a given extreme left and right if existing*)
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

void widthOftree(TreeNode*root){
    if(root==NULL) return;
    int ans = 0;
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        int size = q.size();
        int min = q.front().second;
        int first,last;
        for(int i=0;i<size;i++){
            int curr_index = q.front().second - min;
            TreeNode* curr = q.front().first;
            q.pop();
            if(i==0) first = curr_index;
            if(i==size - 1) last = curr_index;
            if(curr->left){
                q.push({curr->left,curr_index*2+1});
            }
            if(curr->right){
                q.push({curr->right,curr_index*2+2});
            }
            
            ans = max(ans, (last-first+1));
            
        }
    }
    cout<<"The max width of the given tree is: "<<ans <<"\n";
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
	
    widthOftree(root);
	
	
	return 0;
}
