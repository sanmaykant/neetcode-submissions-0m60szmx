class Solution {
public:
    int rotateIdx(int idx, int rotations, int size) {
        idx += rotations;
        if (idx >= size)
            idx -= size;
        return idx;
    }

    int computeRotations(std::vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        int minIdx = 0;

        while (true) {
            int mid = (i + j) / 2;
            if (i == mid) {
                i++;
                continue;
            }

            int pVal = mid == 0 ? nums[nums.size() - 1] : nums[mid - 1];
            int nVal = mid == nums.size() - 1 ? nums[0] : nums[mid + 1];
            
            if (pVal > nums[mid] && nVal > nums[mid]) {
                minIdx = mid;
                break;
            }

            bool l = nums[i] < nums[mid];
            bool r = nums[mid] < nums[j];

            if (l && r) {
                minIdx = 0;
                break;
            } else if (l && !r)
                i = mid;
            else if (!l && r)
                j = mid;
            else
                return -1;
        }

        return minIdx;
    }

    int search(std::vector<int>& nums, int target) {
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        if (nums.size() == 2) {
            if (nums[0] == target)
                return 0;
            else if (nums[1] == target)
                return 1;
            else
                return -1;
        }

        int i = 0;
        int j = nums.size() - 1;
        int rotations = computeRotations(nums);

        while (i < j) {
            int mid = (i + j) / 2;
            int rotatedMid = rotateIdx(mid, rotations, nums.size());
            if (nums[rotatedMid] == target)
                return rotatedMid;

            if (nums[rotatedMid] > target)
                j = mid - 1;
            else if (nums[rotatedMid] < target)
                i = mid + 1;

            if (i == j) {
                int rotatedI = rotateIdx(i, rotations, nums.size());
                return nums[rotatedI] == target ? rotatedI : -1;
            }
        }

        return -1;
    }
};
