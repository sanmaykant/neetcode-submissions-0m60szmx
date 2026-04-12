/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
      std::unordered_map<Node*, Node*> cache;

      Node* node = head;
      while (node) {
        Node* deepCopy = new Node(node->val);
        cache.try_emplace(node, deepCopy);
        node = node->next;
      }

      node = head;
      while (node) {
        Node* deepCopy = cache[node];
        deepCopy->next = cache[node->next];
        deepCopy->random = node->random ? cache[node->random] : nullptr;
        node = node->next;
      }

      return cache[head];
    }
};
