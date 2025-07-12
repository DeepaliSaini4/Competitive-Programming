#include<bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
  int data;
  TreeNode* right;
  TreeNode* left;
  TreeNode(int data){
      this->data = data;
      this->right = NULL;
      this->left = NULL;
  }
};

int kthlargest = INT_MIN;
int kthSmallest = INT_MAX;


void FindKthSmallestValue(TreeNode* root,int &counter,int k){
    if(!root) return ;
    FindKthSmallestValue(root->left,counter,k);
    
    counter++;
    if(counter==k){
        kthSmallest = root->data;
    }
    FindKthSmallestValue(root->right,counter,k);
    

}
void FindKthlargestValue(TreeNode* root,int &counter,int k){
    if(!root ) return;
    FindKthlargestValue(root->right,counter,k);
    counter++;
    if(counter==k){
        kthlargest =  root->data;
    }
  FindKthlargestValue(root->left,counter,k);

}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    //manually constucting of Tree
    TreeNode* root = new TreeNode(90);
    root->left = new TreeNode(60);
    root->left->left = new TreeNode(40);
    root->left->right = new TreeNode(70);
    root->right = new TreeNode(105);
    root->right->right = new TreeNode(110);
    root->right->left = new TreeNode(100);
    
    int counter = 0;
    
    //FindKthlargestValue k =2
    FindKthlargestValue(root,counter,2);
    cout<<kthlargest<<'\n';
 
    //FindKthSmallestValue k =2
    counter = 0;//reser for the next function
    FindKthSmallestValue(root,counter,2);
    cout<<kthSmallest<<'\n';
    
    return 0;
}
