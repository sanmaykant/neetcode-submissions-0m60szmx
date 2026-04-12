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

struct Result {
    int min;
    int max;
    bool valid;
};

class Solution {
public:
    Result dfs(TreeNode* root) {
        if (!root->left && !root->right)
            return { root->val, root->val, true };

        Result result;

        if (root->left) {
            Result leftResult = dfs(root->left);
            if (!leftResult.valid)
                return leftResult;

            if (leftResult.max >= root->val)
                return { -1, -1, false };

            result = { std::min(leftResult.min, root->val), std::max(leftResult.max, root->val), true };
        }
        if (root->right) {
            Result rightResult = dfs(root->right);
            if (!rightResult.valid)
                return rightResult;

            if (rightResult.min <= root->val)
                return { -1, -1, false };

            result = { std::min(rightResult.min, result.min), std::max(rightResult.max, result.max), true };
        }

        return result;
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root).valid;
    }
};
