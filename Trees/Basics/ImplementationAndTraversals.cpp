#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* right;
    TreeNode*left;
    
    TreeNode(int data){
        this->val = data;
        this->right = nullptr;
        this->left = nullptr;
    }
};

//recursive function for building the tree
// returning the ptr to the current subtree
TreeNode* buildtree(vector<int>&treeval,int &index){
    //base case
    //when you reach the leaf node of the tree
    if(index == treeval.size()) return nullptr;
    if(treeval[index] == -1){
        index++;//going to the children
        return nullptr;//no node at the current position
    }
    TreeNode* node = new TreeNode(treeval[index]);
    index++;
    node->left = buildtree(treeval,index);
    node -> right = buildtree(treeval,index);
    return node;
}
// Traversals
void inorder(TreeNode*root){
    if(root == nullptr){
        return;
    }
    inorder(root->left);
    cout<<root->val;
    inorder(root->right);
}
void preorder(TreeNode* node){
    if(node == nullptr){
        return;
    }
    cout<<node->val;
    preorder(node->left);
    preorder(node->right);
}

void postorder(TreeNode* node){
    if(node == nullptr){
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout<<node->val;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    vector<int> treeval=  {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int index = 0;
    TreeNode* root = buildtree(treeval,index);
    cout<<"Inorder:";
    inorder(root);
    cout<<'\n';
    cout<<"Postorder:";
    postorder(root);
    cout<<'\n';
    cout<<"Preorder:";
    preorder(root);
    cout<<'\n';
    return 0;

}
//tc = o(n) and sc = 0(h)
