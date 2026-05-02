class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::vector<std::vector<int>> out;
        std::vector<int> sub;
        int sum = 0;

        std::sort(candidates.begin(), candidates.end(), std::greater<int>());

        std::function<void(int)> backtrack = [&](int i) -> void {
            if (sum == target)
                out.push_back(sub);
            if (sum >= target || i >= candidates.size())
                return;
            
            sub.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(i + 1);

            sub.pop_back();
            sum -= candidates[i];
            while (i+1 < candidates.size() && candidates[i] == candidates[i+1])
                i++;
            backtrack(i+1);
        };
        backtrack(0);

        return out;
    }
};
