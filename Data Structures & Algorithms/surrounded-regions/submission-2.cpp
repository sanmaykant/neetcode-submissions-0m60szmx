template<typename T>
using Grid = std::vector<std::vector<T>>;
using Node = std::pair<int, int>;

static std::array<Node, 4> directions = {
    Node{ -1,  0 },
    Node{  0,  1 },
    Node{  1,  0 },
    Node{  0, -1 },
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (i == 0 || i == board.size() - 1) {
                std::cout << "here" << i << '\n';
                for (int j = 0; j < board[0].size(); j++)
                    dfs(board, { i, j });
            } else {
                dfs(board, { i, 0 });
                dfs(board, { i, board[0].size() - 1 });
            }
        }

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(Grid<char>& matrix, const Node& n) {
        auto& [x, y] = n;

        bool validX = x >= 0 && x < matrix.size();
        bool validY = y >= 0 && y < matrix[0].size();
        if (!validX || !validY)
            return;

        if (matrix[x][y] == '#')
            return;
        
        if (matrix[x][y] == 'O')
            matrix[x][y]  = '#';
        else
            return;

        for (auto& [dirX, dirY] : directions)
            dfs(matrix, { x + dirX, y + dirY });
    }
};
