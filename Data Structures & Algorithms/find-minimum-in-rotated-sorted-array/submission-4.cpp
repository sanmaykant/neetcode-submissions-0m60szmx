class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;
        int min = nums[0];

        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return nums[0] < nums[1] ? nums[0] : nums[1];
        if (nums[i] < nums[j])
            return nums[i];

        while (i <= j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] < min) {
                if (mid > 0 && nums[mid-1] > nums[mid])
                    return nums[mid];
                j = mid;
                if (i+1 < nums.size() && nums[i+1] < nums[i])
                    return nums[i+1];
                i++;
                min = nums[mid];
            } else if (nums[mid] > min) {
                if (i+1 < nums.size() && nums[i+1] < nums[i])
                    return nums[i+1];
                if (i == mid)
                    i++;
                else
                    i = mid;
            }
        }

        return nums[j];
    }
};
