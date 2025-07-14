/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto curr = q.front();
            if (curr == nullptr)
                ss << "#,";
            else
                ss << curr->val << ",";
            q.pop();
            if (curr) {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        string str;
        getline(ss, str, ',');
        int val = stoi(str);
        TreeNode* root = new TreeNode(val);
        queue<TreeNode*> qu;
        qu.push(root);
        while (!qu.empty()) {
            auto node = qu.front();
            qu.pop();

            if (node) {
                getline(ss, str, ',');
                if (str == "#")
                    node->left = nullptr;
                else if (!str.empty())
                    node->left = new TreeNode(stoi(str));
                qu.push(node->left);

                getline(ss, str, ',');

                if (str == "#")
                    node->right = nullptr;
                else if (!str.empty())
                    node->right = new TreeNode(stoi(str));
                qu.push(node->right);
            }
        }
        return root;
    }
};
/*
getline(ss, str, ',') = “give me everything up to the next comma from ss, store it in str, and discard that comma.”

Keeping that call inside if (node) ensures you only ever read tokens when there is a node to assign them to—so your serialization↔deserialization stay in perfect lock-step.
*/
