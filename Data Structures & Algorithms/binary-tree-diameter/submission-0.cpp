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
    int depthsOfNodes(TreeNode* root, std::unordered_map<TreeNode*, int>& cache) {
        if (!root)
            return 0;
        cache.try_emplace(root, 1 + std::max(depthsOfNodes(root->left, cache), depthsOfNodes(root->right, cache)));
        return cache[root];
    }

    int diameterOfBinaryTree(TreeNode* root) {
        std::unordered_map<TreeNode*, int> cache;
        cache.try_emplace(nullptr, 0);
        depthsOfNodes(root, cache);

        std::stack<TreeNode*> st;
        std::unordered_set<TreeNode*> visited;

        st.push(root);
        visited.insert(root);

        int maxDiam = 0;
        while (!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if (node->left && !visited.count(node->left)) {
                visited.insert(node->left);
                st.push(node->left);
            }
            if (node->right && !visited.count(node->right)) {
                visited.insert(node->right);
                st.push(node->right);
            }

            maxDiam = std::max(maxDiam, cache[node->left] + cache[node->right]);
        }

        return maxDiam;
    }
};
