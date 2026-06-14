class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> adjacencyList;
        std::vector<int> inDegree(numCourses, 0);

        for (std::vector<int>& courses : prerequisites) {
            int u = courses[0];
            int v = courses[1];
            adjacencyList.try_emplace(u, std::vector<int>{});
            adjacencyList[u].push_back(v);
            inDegree[v]++;
        }

        std::queue<int> q;
        for (int i = 0; i < numCourses; i++)
            if (!inDegree[i])
                q.push(i);

        while (!q.empty()) {
            int course = q.front();
            q.pop();

            std::vector<int>& neighbours = adjacencyList[course];
            for (int n : neighbours) {
                inDegree[n]--; 
                if (!inDegree[n])
                    q.push(n);
            }
        }

        for (int inDeg : inDegree)
            if (inDeg)
                return false;
        return true;
    }
};
