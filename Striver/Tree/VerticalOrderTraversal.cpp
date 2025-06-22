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

void VeticalOrderTraversal(TreeNode*root){
    if(root == NULL) return;
    map<int,map<int,multiset<int>>>m;
    queue<pair<TreeNode*,pair<int,int>>>q;
    q.push({root,{0,0}});
    while(!q.empty()){
     auto it = q.front();
     q.pop();
     int level = it.second.second;
     int vertical = it.second.first;
     m[vertical][level].insert(it.first->data);
     if(it.first->left){
         q.push({it.first->left,{vertical-1,level+1}});
     }
     if(it.first->right){
         q.push({it.first->right,{vertical+1,level+1}});
     }
    }
    for(auto it:m){
        for(auto it2:it.second){
          for(auto val:it2.second){
              cout<<val<<" ";
          }
    }
          cout<<"\n";
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
	
	VeticalOrderTraversal(root);
	return 0;
}
