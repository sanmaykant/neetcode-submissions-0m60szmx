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
    void invertNode(TreeNode* node) {
      TreeNode* left = node->left;
      TreeNode* right = node->right;
      node->left = right;
      node->right = left;
      
      if (node->left)
        invertNode(node->left);
      if (node->right)
        invertNode(node->right);
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root)
          return root;
        invertNode(root);
        return root;
    }
};
