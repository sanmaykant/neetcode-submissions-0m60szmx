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
    int dfs(TreeNode* root, std::unordered_map<TreeNode*, int>& cache) {
        int& self = root->val;
        cache[root] = self;

        int maxLSum;
        if (root->left) {
            maxLSum = dfs(root->left, cache);
            cache[root] = std::max(cache[root], self + maxLSum);
        }

        int maxRSum;
        if (root->right) {
            maxRSum = dfs(root->right, cache);
            cache[root] = std::max(cache[root], self + maxRSum);
        }

        if (root->left && root->right) {
            cache[root] = std::max(cache[root], self + maxLSum + maxRSum);
            return std::max(self, std::max(self + maxLSum, self + maxRSum));
        }

        if (root->left)
            return std::max(self, self + maxLSum);
        if (root->right)
            return std::max(self, self + maxRSum);

        return root->val;
    }

    int maxPathSum(TreeNode* root) {
        std::unordered_map<TreeNode*, int> cache;
        dfs(root, cache);

        int maxSum = -1000 * cache.size() - 1;
        for (auto& [_, value] : cache)
            maxSum = std::max(maxSum, value);
        
        return maxSum;
    }
};
