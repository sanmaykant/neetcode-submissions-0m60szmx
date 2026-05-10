using pos = std::pair<int, int>;
using board = std::vector<std::string>;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<pos> queens;
        std::vector<board> boards;
        board candidate(n, std::string(n, '.'));

        std::function<void(int)> backtrack = [&](int r) -> void {
            if (r == n) {
                boards.push_back(candidate);
                return;
            }

            for (int c = 0; c < n; c++) {
                pos p = { r, c };
                if (!free(queens, p))
                    continue;

                queens.push_back(p);
                candidate[r][c] = 'Q';

                backtrack(r + 1);

                queens.pop_back();
                candidate[r][c] = '.';
            }
        };
        backtrack(0);

        return boards;
    }

private:
    bool free(const std::vector<pos>& queens, const pos& p) {
        for (auto& q : queens) { 
            bool sameRow = q.first == p.first;
            bool sameCol = q.second == p.second;
            bool sameDiag = std::abs(q.first - p.first) == std::abs(q.second - p.second);
            if (sameRow || sameCol || sameDiag)
                return false;
        }
        return true; 
    } 
};
