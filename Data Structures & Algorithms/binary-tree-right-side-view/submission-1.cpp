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

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (!root)
            return result;

        std::queue<TreeNode*> q1;
        std::queue<TreeNode*> q2;

        q1.push(root);
        result.push_back(root->val);

        int i = 1;
        while (!q1.empty() || !q2.empty()) {
            TreeNode* cand = nullptr;
            if (i % 2 == 0) {
                while (!q2.empty()) {
                    TreeNode* node = q2.front();
                    q2.pop();

                    if (node->left) {
                        q1.push(node->left);
                        cand = node->left;
                    }
                    if (node->right) {
                        q1.push(node->right);
                        cand = node->right;
                    }
                }
                i++;
            } else {
                while (!q1.empty()) {
                    TreeNode* node = q1.front();
                    q1.pop();

                    if (node->left) {
                        q2.push(node->left);
                        cand = node->left;
                    }
                    if (node->right) {
                        q2.push(node->right);
                        cand = node->right;
                    }
                }
                i++;
            }
            if (cand)
                result.push_back(cand->val);
        }

        return result;
    }
};
