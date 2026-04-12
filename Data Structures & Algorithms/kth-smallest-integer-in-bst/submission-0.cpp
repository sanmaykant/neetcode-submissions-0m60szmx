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
    std::vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> st;
        std::vector<int> trav;
        TreeNode* current = root;

        while (current || !st.empty()) {
            while (current) {
                st.push(current);
                current = current->left;
            }

            current = st.top(); st.pop();
            trav.push_back(current->val);
            current = current->right;
        }

        return trav;
    }

    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> inorder = inorderTraversal(root);
        return inorder[k-1];
    }
};
