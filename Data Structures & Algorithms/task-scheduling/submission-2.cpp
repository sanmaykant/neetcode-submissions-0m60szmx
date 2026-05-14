using Task = std::pair<char, int>;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char, int> freqs;
        for (char t : tasks) {
            freqs.try_emplace(t, 0);
            freqs[t]++;
        }

        std::function<bool(Task&, Task&)> cmp = [&](Task& t1, Task& t2) -> bool {
            return t1.second < t2.second; };

        std::priority_queue<Task, std::vector<Task>, decltype(cmp)> maxHeap(cmp);
        for (auto [task, count] : freqs)
            maxHeap.emplace(task, count); 

        std::queue<Task> q; 

        int t = 0;
        while (!maxHeap.empty() || !q.empty()) {
            while (!q.empty() && q.front().second <= t) {
                Task task = q.front();
                q.pop();
                maxHeap.emplace(task.first, freqs[task.first]);
            }

            if (!maxHeap.empty()) {
                Task task = maxHeap.top();
                maxHeap.pop();  
                freqs[task.first]--;
    
                if (freqs[task.first] > 0)
                    q.emplace(task.first, t + n + 1);
            }

            t++;
        }

        return t;
    }
};
