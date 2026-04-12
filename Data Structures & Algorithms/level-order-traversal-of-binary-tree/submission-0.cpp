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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};
        
        std::vector<std::vector<int>> result;
        
        std::queue<TreeNode*> q1;
        q1.push(root);

        std::queue<TreeNode*> q2;
        int i = 1;

        while (!q1.empty() || !q2.empty()) {
            std::vector<int> trav;
            if (i % 2 == 0) {
                while (!q2.empty()) {
                    TreeNode* node = q2.front();
                    q2.pop();

                    trav.push_back(node->val);
                    if (node->left)
                        q1.push(node->left);
                    if (node->right)
                        q1.push(node->right);
                }
                i++;
            } else {
                while (!q1.empty()) {
                    TreeNode* node = q1.front();
                    q1.pop();

                    trav.push_back(node->val);
                    if (node->left)
                        q2.push(node->left);
                    if (node->right)
                        q2.push(node->right);
                }
                i++;
            }
            result.push_back(trav);
        }

        return result;
    }
};
