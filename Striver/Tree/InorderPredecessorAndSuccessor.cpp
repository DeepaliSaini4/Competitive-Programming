/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *      TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
 * };
 **/

class Solution{
	public:
        TreeNode* inorderpredecessor(TreeNode* root,int key){
            TreeNode* pred = nullptr;
           while(root){
            if(key <= root->data){
                root = root->left;
            }else{
                pred = root;
                root = root->right;
            }
           }
           return pred;
        }
        TreeNode* inordersuccessor(TreeNode* root, int key){
            TreeNode* succ = nullptr;
            while(root){
                if(key >= root->data) root = root->right;
                else{
                    succ = root;
                    root = root->left;
                }
            }
            return succ;
        }
		vector<int> succPredBST(TreeNode* root,int key){
			if(!root) return {};
            TreeNode* pred = inorderpredecessor(root,key);
            TreeNode* succ = inordersuccessor(root,key);
            return {
                pred ? pred->data : -1,
                succ ? succ->data : -1
            };
		}
};
