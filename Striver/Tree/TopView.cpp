#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int data;
    TreeNode* right;
    TreeNode* left;
    TreeNode(int data){
        this->data = data;
        this->left =nullptr;
        this->right = nullptr;
    }
};

vector<int> TopView(TreeNode*root){
    vector<int>ans;
    // Check if the tree is empty
    if(root == NULL) return ans;
    map<int,int>m; // horizontal coordinate -> node value
    queue<pair<TreeNode*,int>>q;
    int val = 0;
    q.push({root,val});
    while(!q.empty()){
       auto p = q.front();
        q.pop();
        TreeNode* curr = p.first;
        int hd = p.second;
        if(m.find(hd)==m.end()) //only do entry for a level when not overwriting.
        m[hd] = curr->data;
        if(curr->left) q.push({curr->left, hd-1});
        if(curr->right) q.push({curr->right, hd+1});
    }
    for(auto it:m){
        ans.push_back(it.second);
    }
    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->right->right = new TreeNode(4);
    root->left->right->right->right = new TreeNode(5);

	
	vector<int>ans = TopView(root);
	for(auto it:ans){
	    cout<<it<<" ";
	}
	 return 0;
}
