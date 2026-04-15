class Node {
    public:
        Node()
            : m_Links{}, m_IsEnd(false) {}
        
        bool contains(char ch) { return m_Links[ch - 'a'] != nullptr; }
        void insert(char ch) { m_Links[ch - 'a'] = new Node(); }
        Node* get(char ch) { return m_Links[ch - 'a']; }
        void setEnd() { m_IsEnd = true; }
        bool isEnd() { return m_IsEnd; }

    private:
        std::array<Node*, 26> m_Links;
        bool m_IsEnd;
};

enum class TrieTraverseResult {
    Found,
    NotFound,
    StartsWith
};

using TTR = TrieTraverseResult;

class Trie {
    public:
        Trie()
            : m_Root(new Node()) {}

        void insert(std::string& word) {
            Node* node = m_Root;
            for (char ch : word) {
                if (!node->contains(ch))
                    node->insert(ch);
                node = node->get(ch);
            }
            node->setEnd();
        }

        TTR traverse(std::string& word) {
            Node* node = m_Root;
            for (char ch : word) {
                if (!node->contains(ch))
                    return TTR::NotFound;
                node = node->get(ch);
            }
            return node->isEnd() ? TTR::Found : TTR::StartsWith;
        }

    private:
        Node* m_Root;
};

class Solution {
public:
    std::vector<std::pair<int, int>> neighbours(std::vector<std::vector<char>>& board, int i, int j) {
        std::vector<std::pair<int, int>> coords = {
            {i, j + 1},
            {i + 1, j},
            {i, j - 1},
            {i - 1, j}
        };

        std::vector<std::pair<int, int>> ns;
        for (auto& [a, b] : coords)
            if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size())
                ns.emplace_back(a, b);
        return ns;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        for (std::string& word : words)
            trie.insert(word);

        std::unordered_set<std::string> found;
        std::string word = "";
        std::vector<std::vector<bool>> visited(
                board.size(), std::vector<bool>(board[0].size(), false));

        std::function<void(int i, int j)> dfs = [&](int i, int j) -> void {
            visited[i][j] = true;
            word += board[i][j];

            switch (trie.traverse(word)) {
                case TTR::Found: {
                    found.insert(word);
                    break;
                }
                case TTR::NotFound: {
                    word = word.substr(0, word.size() - 1);
                    visited[i][j] = false;
                    return;
                }
                case TTR::StartsWith: break;
            }

            std::vector<std::pair<int, int>> ns = neighbours(board, i, j);

            for (auto& [ni, nj] : ns) {
                if (visited[ni][nj])
                    continue;
                dfs(ni, nj);
            }

            word = word.substr(0, word.size() - 1);
            visited[i][j] = false;
        };

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                word = "";
                for (auto& row : visited)
                    std::fill(row.begin(), row.end(), false);
                dfs(i, j);
            }
        }

        std::vector<std::string> output(found.begin(), found.end());
        return output;
    }
};
