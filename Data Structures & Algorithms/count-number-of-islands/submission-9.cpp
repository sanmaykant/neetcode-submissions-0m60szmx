#include <vector>
#include <queue>
#include <iostream>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;

        const int dr[] = {0, 0, 1, -1};
        const int dc[] = {1, -1, 0, 0};

        std::queue<int> q;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    ++islandCount;
                    
                    grid[i][j] = '0';
                    q.push(i * cols + j);

                    while (!q.empty()) {
                        int curr = q.front();
                        q.pop();

                        int r = curr / cols;
                        int c = curr % cols;

                        for (int d = 0; d < 4; ++d) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];

                            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == '1') {
                                grid[nr][nc] = '0';
                                q.push(nr * cols + nc);
                            }
                        }
                    }
                }
            }
        }

        return islandCount;
    }
};