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
    int cacheHeights(TreeNode* root, std::unordered_map<TreeNode*, int>& cache) {
        if (!root)
            return 0;
        cache.try_emplace(root, 1 + std::max(cacheHeights(root->left, cache), cacheHeights(root->right, cache)));
        return (*cache.find(root)).second;
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        
        std::unordered_map<TreeNode*, int> cache;
        cacheHeights(root, cache);

        cache.try_emplace(nullptr, 0);

        std::queue<TreeNode*> q;
        std::unordered_set<TreeNode*> visited;

        q.push(root);
        visited.insert(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (std::abs(cache[node->left] - cache[node->right]) > 1)
                return false;

            if (node->left) {
                q.push(node->left);
                visited.insert(node->left);
            }
            if (node->right) {
                q.push(node->right);
                visited.insert(node->right);
            }
        }

        return true;
    }
};
