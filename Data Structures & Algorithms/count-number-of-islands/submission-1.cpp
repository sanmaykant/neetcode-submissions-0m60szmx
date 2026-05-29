using Coord = std::pair<int, int>;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        std::vector<std::vector<bool>> visited(
            grid.size(), std::vector<bool>(grid[0].size(), false));
        
        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    exploreIsland({ i, j }, grid, visited);
                    count++; 
                } 
            }
        }
        return count;
    }

private: 
    void exploreIsland(
            const Coord& coord,
            std::vector<std::vector<char>>& grid,
            std::vector<std::vector<bool>>& visited) { 
        std::function<void(Coord)> backtrack = [&](Coord coord) -> void {
            if (visited[coord.first][coord.second] || grid[coord.first][coord.second] == '0')
                return;

            visited[coord.first][coord.second] = true;
            std::vector<Coord> candidates = neighbours(
                coord, { visited.size(), visited[0].size() });
            for (Coord& c : candidates)
                backtrack(c);
        };
        backtrack(coord);
    }

    std::vector<Coord> neighbours(const Coord& coord, const Coord& gridSize) {
        std::vector<Coord> potentialNeighbours = {
            { coord.first, coord.second + 1 },
            { coord.first + 1, coord.second },
            { coord.first, coord.second - 1 },
            { coord.first - 1, coord.second },
        };

        std::vector<Coord> validNeighbours;
        for (Coord& c : potentialNeighbours) {
            bool validFirst = c.first >= 0 && c.first < gridSize.first;
            bool validSecond = c.second >= 0 && c.second < gridSize.second;
            if (validFirst && validSecond)
                validNeighbours.push_back(c);
        }
        return validNeighbours;
    }
};
