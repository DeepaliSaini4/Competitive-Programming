
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr = root;
        while(curr!=NULL){
           //3 cased situation here!
          //reached the extreme left end of the tree and start filling the inorder answer
           if(curr->left == NULL){
            inorder.push_back(curr->val);
            curr = curr->right;
           }else{
            TreeNode* prev = curr->left;
            while(prev->right&& prev->right!=curr){
                prev = prev->right;
             //forming of thread
            if(prev->right==NULL){
                prev -> right = curr;
                curr = curr->left;
            }else{
            }//dettaching the thread 
                prev->right = NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
           }
        }
     return inorder; 
    }
};
