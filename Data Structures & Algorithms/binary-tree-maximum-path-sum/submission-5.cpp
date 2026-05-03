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
    int dfs(TreeNode* node, int* maxSum) {
        if (!node)
            return -1001;

        int lSum = dfs(node->left, maxSum);
        int rSum = dfs(node->right, maxSum);
        *maxSum = std::max(*maxSum, std::max(lSum, rSum));

        int currentMaxSum = node->val + lSum + rSum;
        currentMaxSum = std::max(currentMaxSum, node->val + lSum);
        currentMaxSum = std::max(currentMaxSum, node->val + rSum);
        currentMaxSum = std::max(node->val, currentMaxSum);

        *maxSum = std::max(*maxSum, currentMaxSum);

        return std::max(node->val, node->val + std::max(lSum, rSum));
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = root->val;
        dfs(root, &maxSum);
        return maxSum;
    }
};
