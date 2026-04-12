class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefProdArray(nums.size());
        std::vector<int> suffProdArray(nums.size());

        int prefProd = nums[0];
        int suffProd = nums[nums.size() - 1];

        prefProdArray[0] = prefProd;
        suffProdArray[nums.size() - 1] = suffProd;

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || i == nums.size() - 1)
                continue;
            int j = nums.size() - 1 - i;

            prefProd *= nums[i];
            suffProd *= nums[j];

            prefProdArray[i] = prefProd;
            suffProdArray[j] = suffProd;
        }

        std::vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int prevProd = i > 0 ? prefProdArray[i - 1] : 1;
            int nextProd = i + 1 < nums.size() ? suffProdArray[i + 1] : 1;
            result.push_back(prevProd * nextProd);
        }
        return result;
    }
};
