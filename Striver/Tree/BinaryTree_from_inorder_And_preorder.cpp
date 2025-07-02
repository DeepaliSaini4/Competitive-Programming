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

TreeNode* CreateTree(vector<int>&preorder,vector<int>&inorder,int inorderstart,int inorderend, int preorderstart, int preorderend, map<int,int> &m){
    //condition for leaf node in the recursion is the base conditon
    if(inorderstart>inorderend||preorderstart>preorderend){
        return NULL;
    }
    TreeNode* root = new TreeNode(preorder[preorderstart]);
    int inroot = m[root->data];
    int numsleft = inroot-inorderstart;
    
    //left subtree creation call
   root->left =  CreateTree(preorder,inorder,inorderstart,inroot - 1,preorderstart+1,preorderstart+numsleft,m);
    
    //righ subtree creationcall 
   root->right = CreateTree(preorder,inorder,inroot+1,inorderend ,preorderstart+numsleft+1,preorderend,m);
    
    return root;
    
}
//function to print the tree
void printtree(TreeNode* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
   if(root->left) printtree(root->left);
   if(root->right) printtree(root->right);
   return;
}

void buildtree(vector<int>&inorder,vector<int>&preorder){
    int n = inorder.size();
    int m = preorder.size();
    map<int,int>mymap;
    int cnt = 0;
    for(auto it:inorder){
        mymap[it] = cnt++;
    }
    //functional call in order to create the tree fro. inorder and preorder traversals
   TreeNode* root = CreateTree(preorder,inorder,0,n-1,0,m-1,mymap);
   printtree(root);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder  = {4, 2, 5, 1, 3};
    buildtree(inorder,preorder);
    return 0;
     
}
