class Node {
    public:
        Node() = default;

        bool contains(char ch) { return m_Links[ch - 'a'] != nullptr; }

        void insert(char ch) { m_Links[ch - 'a'] = new Node(); }

        Node* get(char ch) { return m_Links[ch - 'a']; }

        void setEnd() { m_IsEnd = true; }

        bool isEnd() { return m_IsEnd; }

    private:
        std::array<Node*, 26> m_Links;
        bool m_IsEnd = false;
};

class PrefixTree {
public:
    PrefixTree()
        : m_Root(new Node()) {}
    
    void insert(string word) {
        Node* node = m_Root;
        for (char ch : word) {
            if (!node->contains(ch))
                node->insert(ch);
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = m_Root;
        for (char ch : word) {
            if (!node->contains(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = m_Root;
        for (char ch : prefix) {
            if (!node->contains(ch))
                return false;
            node = node->get(ch);
        }
        return true;
    }

private:
    Node* m_Root;
};
