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

int maximumsum(TreeNode* root, int &maxi){
    if(root == NULL) return 0;
    
    int leftmaxsum =max(0, maximumsum(root->left,maxi));
    int rightmaxsum = max(0,maximumsum(root->right,maxi));
    
    maxi = max(maxi, leftmaxsum+rightmaxsum+root->data);
    return max(leftmaxsum,rightmaxsum)+root->data;
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
    
    int maxsum = INT_MIN;
    maximumsum(root, maxsum);
    cout<<maxsum;
    
       return 0;
     
}
