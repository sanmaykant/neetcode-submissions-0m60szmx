class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        std::unordered_map<int, std::vector<int>> graph;
        for (std::vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph.try_emplace(u, std::vector<int>{});
            graph.try_emplace(v, std::vector<int>{});

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        bool cycleDetected = false;
        std::unordered_set<int> visited;

        std::function<void(int, int)> dfs = [&](int n, int parent) -> void { 
            if (visited.count(n)) {
                std::cout << "Cycle detected! " << parent << ' ' << n << '\n';
                cycleDetected = true;
                return;
            }

            std::cout << n << '\n';

            visited.insert(n);
            for (int child : graph[n])
                if (child != parent)
                    dfs(child, n); 
        };
        dfs(0, -1);

        std::cout << visited.size() << ' ' << cycleDetected;
        if (visited.size() < n || cycleDetected)
            return false;
        return true;
    }
};
