#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right =NULL;
    }
};

void  RightRecursion(TreeNode* root,int level,vector<int>&rightview){
    if(root == NULL){
        return;
    }
    if(rightview.size()==level){
        rightview.push_back(root->data);
    }
    //proceed to the right subtree first
    RightRecursion(root->right,level+1,rightview);
    //incase right child not present but left present for the same level
    RightRecursion(root->left,level+1,rightview);
    return;
}

void LeftRecursion(TreeNode*root,int level,vector<int>&leftview){
    if(root == NULL) return;
    if(leftview.size()==level) leftview.push_back(root->data);
    LeftRecursion(root->left,level+1,leftview);
    LeftRecursion(root->right,level+1,leftview);
    return;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	//constructing the binary tree manually
	TreeNode* root = new TreeNode(10);
	root->right = new TreeNode(15);
	root->right->right = new TreeNode(18);
	root->right->left = new TreeNode(14);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(6);
	
	vector<int>rightview;
	vector<int>leftview;
	
	RightRecursion(root,0,rightview);
	LeftRecursion(root,0,leftview);
	
	cout<<"Rightview:";
	for(auto it:rightview){
	    cout<<it;
	}
	cout<<'\n'<<"Leftview:";
	for(auto it:leftview){
	    cout<<it;
	}
	return 0;
}
