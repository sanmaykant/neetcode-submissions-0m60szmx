class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int count = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    exploreIsland(grid, i, j, rows, cols);
                    count++; 
                } 
            }
        }
        return count;
    }

private: 
    void exploreIsland(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0')
            return;

        grid[r][c] = '0';

        exploreIsland(grid, r + 1, c, rows, cols);
        exploreIsland(grid, r - 1, c, rows, cols);
        exploreIsland(grid, r, c + 1, rows, cols);
        exploreIsland(grid, r, c - 1, rows, cols);
    }
};