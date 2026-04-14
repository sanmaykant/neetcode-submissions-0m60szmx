class Node {
    public:
        Node()
            : m_Links{}, m_IsEnd(false) {}

        void insert(char ch) { m_Links[ch - 'a'] = new Node(); }
        bool contains(char ch) { return m_Links[ch - 'a'] != nullptr; }
        Node* get(char ch) { return m_Links[ch - 'a']; }
        void setEnd() { m_IsEnd = true; }
        bool isEnd() { return m_IsEnd; }

        std::vector<Node*> getLinks() {
            std::vector<Node*> links;
            for (auto node : m_Links)
                if (node)
                    links.push_back(node);
            return links;
        }

    private:
        std::array<Node*, 26> m_Links;
        bool m_IsEnd;
};

class WordDictionary {
public:
    WordDictionary()
        : m_Root(new Node()) {}
    
    void addWord(string word) {
        Node* node = m_Root;
        for (char ch : word) {
            if (!node->contains(ch))
                node->insert(ch);
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool searchFrom(string word, int index, Node* root) {
        Node* node = root;
        for (int i = index; i < word.size(); i++) {
            char ch = word[i];

            if (ch == '.') {
                for (auto link : node->getLinks())
                    if (searchFrom(word, i+1, link))
                        return true;
                return false;
            }

            if (ch != '.' && !node->contains(ch))
                return false;
            node = node->get(ch);
        }
        return node->isEnd();

    }
    
    bool search(string word) {
        return searchFrom(word, 0, m_Root);
    }

private:
    Node* m_Root;
};
