/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";

        std::queue<TreeNode*> q;
        q.push(root);

        std::string result = "";
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                result += "n,";
                continue;
            }

            result += std::to_string(node->val) + ",";
            q.push(node->left);
            q.push(node->right);
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string token;

        getline(ss, token, ',');
        TreeNode* root = new TreeNode(stoi(token));

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Left child
            if (!getline(ss, token, ',')) break;
            if (token != "n") {
                node->left = new TreeNode(stoi(token));
                q.push(node->left);
            }

            // Right child
            if (!getline(ss, token, ',')) break;
            if (token != "n") {
                node->right = new TreeNode(stoi(token));
                q.push(node->right);
            }
        }

        return root;
    }
};
