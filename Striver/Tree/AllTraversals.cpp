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

void AllTraversal(TreeNode* root){
    if(root == NULL) return;
    vector<int> Preorder;
    vector<int> Postorder;
    vector<int> Inorder;
    stack<pair<TreeNode*,int>>s;
    s.push({root,1});
    while(!s.empty()){
        auto now = s.top();
        TreeNode* curr = now.first;
        int val = now.second;
        if(val==1){
            s.pop();
            Preorder.push_back(curr->data);
            s.push({curr,2});
            if(curr->left)
            s.push({curr->left,1});
            
        }else if(val == 2){
            s.pop();
            Inorder.push_back(curr->data);
            s.push({curr,3});
            if(curr->right)
            s.push({curr->right,1});
        }else if (val == 3){
            s.pop();
            Postorder.push_back(curr->data);
        }
        
    }
    cout<<"Preorder: ";
    for(auto it:Preorder){
        cout<<it<<" ";
    }
    cout<<'\n';
    
     cout<<"Inorder: ";
    for(auto it:Inorder){
        cout<<it<<" ";
    }
    cout<<'\n';
    
     cout<<"Postorder: ";
    for(auto it:Postorder){
        cout<<it<<" ";
    }
    cout<<'\n';
    
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
     AllTraversal(root);
	

}
