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
    int goodNodes(TreeNode* root) {
        int count = 0;
        if (!root)
            return count;

        std::stack<std::pair<TreeNode*, int>> st;
        st.emplace(root, root->val);
        count++;

        while (!st.empty()) {
            auto [node, val] = st.top();
            st.pop();

            if (node->right) {
                if (node->right->val >= val)
                    count++;
                st.emplace(node->right, std::max(val, node->right->val));
            }
            if (node->left) {
                if (node->left->val >= val)
                    count++;
                st.emplace(node->left, std::max(val, node->left->val));
            }
        }

        return count;
    }
};
