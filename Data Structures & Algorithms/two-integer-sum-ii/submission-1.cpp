class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size() - 1;
        for (int i = 0; i < numbers.size(); i++) {
            if (i > 0 && numbers[i] < numbers[i-1])
                return {};

            int req = target - numbers[i];
            while (j > i && req < numbers[j])
                j--;

            if (req == numbers[j])
                return { i + 1, j + 1 };
            j = numbers.size() - 1;
        }
        return std::vector<int>{};
    }
};
