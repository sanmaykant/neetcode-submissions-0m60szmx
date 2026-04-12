class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<char>> seenRows(9);
        std::vector<std::unordered_set<char>> seenCols(9);
        std::vector<std::unordered_set<char>> seenGrids(9);

        for (int i = 0; i < 9; i++) {
            auto& row = board[i];
            auto& seenRow = seenRows[i];
            for (int j = 0; j < 9; j++) {
                char& value = row[j];
                if (value == '.')
                    continue;

                if (seenRow.count(value)) {
                    return false;
                } else {
                    seenRow.insert(value);
                }
            }
        }

        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < 9; i++) {
                char& value = board[i][j];
                auto& seenCol = seenCols[j];

                if (value == '.')
                    continue;

                if (seenCol.count(value)) {
                    return false;
                } else {
                    seenCol.insert(value);
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            auto& grid = seenGrids[i];
            for (int j = 0; j < 9; j++) {
                int it = (int) (std::floor((float) j / 9.f * 3.f) + std::floor((float) i / 3.f) * 3.f);
                int jt = j % 3 + (i * 3) % 9;

                char& value = board[it][jt];
                if (value == '.')
                    continue;

                if (grid.count(value)) {
                    return false;
                } else {
                    grid.insert(value);
                }
            }
        }
        return true;
    }
};
