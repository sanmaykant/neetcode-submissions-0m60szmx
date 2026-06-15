class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false;

        std::vector<std::vector<int>> graph(n);
        for (std::vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool cycleDetected = false;
        std::unordered_set<int> visited;

        std::function<void(int, int)> dfs = [&](int n, int parent) -> void { 
            if (visited.count(n)) {
                cycleDetected = true;
                return;
            }

            visited.insert(n);
            for (int child : graph[n])
                if (child != parent)
                    dfs(child, n); 
        };
        dfs(0, -1);

        if (visited.size() < n || cycleDetected)
            return false;
        return true;
    }
};
