class Solution {
public:
    int findMin(vector<int> &nums) {
        int i = 0;
        int j = nums.size() - 1;
        int min = nums[0];

        while (true) {
            int mid = (i + j) / 2;
            int pVal = mid == 0 ? nums[nums.size() - 1] : nums[mid - 1];
            int nVal = mid + 1 < nums.size() ? nums[mid + 1] : nums[0];

            if (nums[mid] < pVal && nums[mid] < nVal) {
                min = nums[mid];
                break;
            }

            bool l = nums[mid] > nums[i];
            bool r = nums[mid] < nums[j];

            if (l && r) { // left: asc, right: asc
                min = nums[0];
                break;
            }
            else if (l && !r) // left: asc, right: desc
                i = mid;
            else if (!l && r) // left: desc, right: asc
                j = mid;
            else if (!l && !r) { // left: desc, right: desc (in case of 2 nums)
                min = nums[nums.size() - 1];
                break;
            }
        }

        return min;
    }
};
