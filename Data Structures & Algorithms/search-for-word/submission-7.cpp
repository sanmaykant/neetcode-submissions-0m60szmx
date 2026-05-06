class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        std::vector<std::vector<bool>> visited(
            board.size(), std::vector<bool>(board[0].size(), false));
        bool found = false;

        int size = 0;
        std::function<void(int i, int j)> backtrack = [&](int i, int j) -> void {
            if (visited[i][j] || found || word[size] != board[i][j])
                return;

            visited[i][j] = true;
            size++;

            if (size == word.size()) {
                found = true;
                return;
            }

            std::vector<std::pair<int, int>> validNeighbours = neighbours(board, i, j);
            for (auto& n : validNeighbours)
                backtrack(n.first, n.second);

            visited[i][j] = false;
            size--;
        };

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++)
                if (!found && board[i][j] == word[0])
                    backtrack(i, j);
        }

        return found;
    }

private:
    std::vector<std::pair<int, int>> neighbours(
            std::vector<std::vector<char>>& board, int i, int j) {
        std::array<std::pair<int, int>, 4> candidates = {
            std::pair<int, int>{ i, j - 1 },
            std::pair<int, int>{ i - 1, j },
            std::pair<int, int>{ i, j + 1 },
            std::pair<int, int>{ i + 1, j }
        };

        std::vector<std::pair<int, int>> validNeighbours;
        for (auto& c : candidates) {
            if (c.first >= 0 &&
                c.first < board.size() &&
                c.second >= 0 &&
                c.second < board[0].size())
                    validNeighbours.push_back(c);
        }
        return validNeighbours;
    }
};
