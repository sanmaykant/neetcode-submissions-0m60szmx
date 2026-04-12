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
    std::vector<TreeNode*> searchTree(TreeNode* root, int val) {
        std::queue<TreeNode*> q;
        q.push(root);

        std::vector<TreeNode*> candidates;

        while (!q.empty()) {
            TreeNode*& node = q.front();
            q.pop();

            if (node->val == val)
                candidates.push_back(node);

            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }

        return candidates;
    }

    bool isSame(TreeNode* r1, TreeNode* r2) {
        std::stack<std::pair<TreeNode*, TreeNode*>> st;
        st.emplace(r1, r2);

        while (!st.empty()) {
            auto [n1, n2] = st.top();
            st.pop();

            if (!n1 && !n2)
                continue;
            if (!n1 || !n2 || n1->val != n2->val)
                return false;
            
            st.emplace(n1->right, n2->right);
            st.emplace(n1->left, n2->left);
        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::vector<TreeNode*> candidates = searchTree(root, subRoot->val);
        if (candidates.size() == 0)
            return false;

        for (TreeNode* candidate : candidates)
            if (isSame(candidate, subRoot))
                return true;

        return false;
    }
};
