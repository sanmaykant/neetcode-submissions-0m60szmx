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
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;

        std::stack<std::pair<TreeNode*, int>> st;
        st.push({ root, 1 });

        std::unordered_set<TreeNode*> visited;
        visited.insert(root);

        int maxDepth = 0;
        while (!st.empty()) {
            auto [top, depth] = st.top();
            st.pop();

            maxDepth = std::max(maxDepth, depth);

            if (top->left && !visited.count(top->left)) {
                visited.insert(top->left);
                st.push({ top->left, depth + 1 });
            }
            if (top->right && !visited.count(top->right)) {
                visited.insert(top->right);
                st.push({ top->right, depth + 1 });
            }
        }

        return maxDepth;
    }
};
