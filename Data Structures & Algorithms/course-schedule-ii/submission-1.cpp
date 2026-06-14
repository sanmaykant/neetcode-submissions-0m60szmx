class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        std::unordered_map<int, std::vector<int>> adjacencyList;
        std::vector<int> inDegree(numCourses, 0);

        for (std::vector<int>& courses : prerequisites) {
            int course = courses[0];
            int prereq = courses[1];
            adjacencyList.try_emplace(prereq, std::vector<int>{});
            adjacencyList[prereq].push_back(course);
            inDegree[course]++;
        }

        std::queue<int> q;
        for (int i = 0; i < inDegree.size(); i++)
            if (!inDegree[i])
                q.push(i);

        int traversedCourses = 0;
        std::vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            order.push_back(course);
            traversedCourses++;
            q.pop();

            std::vector<int>& neighbours = adjacencyList[course];
            for (int n : neighbours) {
                inDegree[n]--;
                if (!inDegree[n])
                    q.push(n);
            }
        }

        if (numCourses > traversedCourses)
            return {};
        return order;
    }
};
