struct Node {
    int x;
    int y;
    int depth;

    Node(int x, int y, int depth)
        : x(x), y(y), depth(depth) {}
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        std::queue<Node> q;

        int count = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2)
                    q.push({ i, j, 0 });
                if (grid[i][j] == 0)
                    count++;
            } 
        }
        count = grid.size() * grid[0].size() - count;

        int maxDepth = 0;
        while (!q.empty()) {
            Node n = q.front();
            q.pop();

            bool validX = n.x >= 0 && n.x < grid.size();
            bool validY = n.y >= 0 && n.y < grid[0].size();
            if (!validX || !validY)
                continue;

            bool isEmpty = grid[n.x][n.y] == 0;
            bool isVisited = visited[n.x][n.y];
            if (isEmpty || isVisited)
                continue;

            visited[n.x][n.y] = true;
            maxDepth = std::max(maxDepth, n.depth);
            count--;

            std::array<Node, 4> neighbours = {
                Node{ n.x - 1, n.y, n.depth + 1 },
                Node{ n.x, n.y + 1, n.depth + 1 },
                Node{ n.x + 1, n.y, n.depth + 1 },
                Node{ n.x, n.y - 1, n.depth + 1 },
            };
            for (Node& neigh : neighbours)
                q.push(neigh);
        }

        if (count != 0)
            return -1;
        return maxDepth;
    }
};
