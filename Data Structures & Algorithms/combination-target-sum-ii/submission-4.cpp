class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::set<int, std::greater<int>> nums;
        std::unordered_map<int, int> freqs;

        for (int num : candidates) {
            nums.insert(num);
            freqs.try_emplace(num, 0);
            freqs[num]++;
        }

        std::vector<int> numsVec(nums.begin(), nums.end());
        std::vector<int> sub;
        int sum = 0;

        std::vector<std::vector<int>> out;

        std::function<void(int)> backtrack = [&](int i) -> void {
            if (sum == target)
                out.push_back(sub);
            if (i >= numsVec.size() || sum >= target)
                return;

            int num = numsVec[i];
            if (freqs[num] > 0) {
                sub.push_back(num);
                sum += num;
                freqs[num]--;

                backtrack(i);

                sub.pop_back();
                sum -= num;
                freqs[num]++;
            }

            backtrack(i+1);
        };

        backtrack(0);
        return out;
    }
};
