using Grid = std::vector<std::vector<int>>;
using Coord = std::pair<int, int>;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                maxArea = std::max(maxArea, exploreIsland(grid, { i, j }));
        return maxArea;
    }

private:
    int exploreIsland(Grid& grid, const Coord& coord) {
        bool validX = coord.first >= 0 && coord.first < grid.size();
        bool validY = coord.second >= 0 && coord.second < grid[0].size();
        if (!validX || !validY)
            return 0;

        bool isWater = grid[coord.first][coord.second] == 0;
        if (isWater)
            return 0;

        grid[coord.first][coord.second] = 0;
        int area = 1;

        area += exploreIsland(grid, { coord.first, coord.second + 1 });
        area += exploreIsland(grid, { coord.first + 1, coord.second });
        area += exploreIsland(grid, { coord.first, coord.second - 1 });
        area += exploreIsland(grid, { coord.first - 1, coord.second });

        return area;
    }
};
