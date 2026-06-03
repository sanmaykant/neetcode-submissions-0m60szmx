template<typename T>
using Grid = std::vector<std::vector<T>>;
using Node = std::pair<int, int>;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 0)
                    bfs(grid, Node{ i, j });
    }

private: 
    void bfs(Grid<int>& grid, const Node& root) {
        Grid<bool> visited = initVisited(grid);
        std::queue<std::pair<Node, int>> q;
        q.push({ root, 0 });

        while (!q.empty()) {
            auto [n, depth] = q.front();
            q.pop();

            bool validFirst = n.first >= 0 && n.first < grid.size();
            bool validSecond = n.second >= 0 && n.second < grid[0].size();
            if (!validFirst || !validSecond)
                continue;

            bool inVisited = visited[n.first][n.second];
            bool isWater = grid[n.first][n.second] == -1;
            if (inVisited || isWater)
                continue;

            visited[n.first][n.second] = true; 
            grid[n.first][n.second] = std::min(depth, grid[n.first][n.second]);

            std::array<Node, 4> neighbours = {
                Node{ n.first - 1, n.second },
                Node{ n.first, n.second + 1 },
                Node{ n.first + 1, n.second },
                Node{ n.first, n.second - 1 },
            };
            for (Node& neigh : neighbours)
                q.push({ neigh, depth + 1 });
        }
    }

    inline Grid<bool> initVisited(Grid<int>& grid) {
        return std::vector<std::vector<bool>>(grid.size(), std::vector<bool>(grid[0].size(), false));
    }
};
