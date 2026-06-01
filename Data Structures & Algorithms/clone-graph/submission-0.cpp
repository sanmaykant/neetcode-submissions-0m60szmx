/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
            return nullptr;
        return dfs(node);
    }

private:
    Node* dfs(Node* node) {
        if (nodes.count(node->val))
            return nodes[node->val];

        Node* nodeCopy = new Node(node->val);
        nodes[nodeCopy->val] = nodeCopy;

        for (Node* n : node->neighbors)
            nodeCopy->neighbors.push_back(dfs(n));

        return nodeCopy;
    }

private:
    std::unordered_map<int, Node*> nodes; 
};
