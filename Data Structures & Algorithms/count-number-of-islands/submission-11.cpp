#include <vector>
#include <queue>

class Solution {
public:
    void bfs(std::vector<std::vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        std::queue<std::pair<int, int>> q;
        q.push({i, j});
        
        while (!q.empty()) {
            std::pair<int, int> cur = q.front();
            q.pop();
            
            int il = cur.first;
            int jl = cur.second;
            
            if (il - 1 >= 0 && grid[il - 1][jl] == '1') {
                q.push({il - 1, jl});
                grid[il - 1][jl] = '0';
            }
            
            if (il + 1 < m && grid[il + 1][jl] == '1') {
                q.push({il + 1, jl});
                grid[il + 1][jl] = '0';
            }
            
            if (jl - 1 >= 0 && grid[il][jl - 1] == '1') {
                q.push({il, jl - 1});
                grid[il][jl - 1] = '0';
            }
            
            if (jl + 1 < n && grid[il][jl + 1] == '1') {
                q.push({il, jl + 1});
                grid[il][jl + 1] = '0';
            }
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    bfs(grid, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};