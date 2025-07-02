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

TreeNode* CreateTree(vector<int>&postorder,vector<int>&inorder,int inorderstart,int inorderend, int postorderstart, int postorderend, map<int,int> &m){
    //condition for leaf node in the recursion is the base conditon
    if(inorderstart>inorderend||postorderstart>postorderend){
        return NULL;
    }
    TreeNode* root = new TreeNode(postorder[postorderend]);
    int inroot = m[root->data];
    int numsleft = inroot-inorderstart;
    
    //leftsubtree 
    root->left = CreateTree(postorder,inorder,inorderstart,inroot-1,postorderstart, postorderstart + numsleft - 1,m);
    
    
    //rightsubtree
    root->right = CreateTree(postorder,inorder,inroot+1,inorderend,postorderstart+numsleft,postorderend-1,m);
    
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

void buildtree(vector<int>&inorder,vector<int>&postorder){
    int n = inorder.size();
    int m = postorder.size();
    map<int,int>mymap;
    int cnt = 0;
    for(auto it:inorder){
        mymap[it] = cnt++;
    }
    //functional call in order to create the tree fro. inorder and preorder traversals
   TreeNode* root = CreateTree(postorder,inorder,0,n-1,0,m-1,mymap);
   printtree(root);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
   vector<int> inorder   = {4, 2, 5, 1, 3};
    vector<int> postorder = {4, 5, 2, 3, 1};
    buildtree(inorder,postorder);
    return 0;
     
}
