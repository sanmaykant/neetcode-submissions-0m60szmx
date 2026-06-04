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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        Grid<bool> pacific(heights.size(), std::vector<bool>(heights[0].size(), false));
        Grid<bool> atlantic(heights.size(), std::vector<bool>(heights[0].size(), false));

        for (int i = 0; i < heights.size(); i++) {
            if (i > 0) {
                dfs(heights, pacific, { i, 0 });
                continue;
            }

            for (int j = 0; j < heights[0].size(); j++)
                dfs(heights, pacific, { i, j });
        }

        for (int i = heights.size() - 1; i >= 0; i--) {
            if (i < heights.size() - 1) {
                dfs(heights, atlantic, { i, heights[0].size() - 1 });
                continue;
            }

            for (int j = 0; j < heights[0].size(); j++)
                dfs(heights, atlantic, { i, j });
        }

        std::vector<std::vector<int>> out;
        for (int i = 0; i < heights.size(); i++)
            for (int j = 0; j < heights[0].size(); j++)
                if (pacific[i][j] && atlantic[i][j])
                    out.push_back({ i, j });
        return out;
    }

private:
    void dfs(Grid<int>& heights, Grid<bool>& visited, const Node& node) {
        auto& [x, y] = node;
        visited[x][y] = true; 

        for (auto& [dirX, dirY] : directions) {
            Node n = { x + dirX, y + dirY };
            auto& [nx, ny] = n;

            bool validX = nx >= 0 && nx < heights.size();
            bool validY = ny >= 0 && ny < heights[0].size();
            if (!validX || !validY)
                continue;

            bool isVisited = visited[nx][ny];
            bool isSmaller = heights[nx][ny] < heights[x][y];
            if (isVisited || isSmaller)
                continue;

            dfs(heights, visited, n);
        }
    }
};
