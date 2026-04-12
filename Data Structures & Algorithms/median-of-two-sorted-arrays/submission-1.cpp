class Solution {
public:
  double findMedianSortedArrays(std::vector<int> &nums1,
                                std::vector<int> &nums2) {
    if (nums2.size() > nums1.size())
      return findMedianSortedArrays(nums2, nums1);

    if (nums2.size() == 0)
      return medianTwoArrays(nums1, nums2);

    if (nums1[nums1.size() - 1] <= nums2[0])
      return medianTwoArrays(nums1, nums2);
    if (nums2[nums2.size() - 1] <= nums1[0])
      return medianTwoArrays(nums2, nums1);

    int total = nums1.size() + nums2.size();
    int half = (total + 1) / 2;
    bool even = total % 2 == 0;

    int i = 0;
    int j = nums2.size() - 1;

    while (true) {
      int mid = (i + j) / 2;
      int req = half - mid - 1;

      double nums1LeftEnd =
          req == 0 ? -std::numeric_limits<double>::infinity() : nums1[req - 1];
      double nums1RightStart = nums1[req];
      double nums2LeftEnd = nums2[mid];
      double nums2RightStart = mid + 1 == nums2.size()
                                   ? std::numeric_limits<double>::infinity()
                                   : nums2[mid + 1];

      if (nums1LeftEnd <= nums2RightStart && nums2LeftEnd <= nums1RightStart)
        return even ? (double)(std::max(nums1LeftEnd, nums2LeftEnd) +
                               std::min(nums1RightStart, nums2RightStart)) /
                          2.
                    : std::max(nums1LeftEnd, nums2LeftEnd);

      if (nums1LeftEnd > nums2RightStart)
        i = mid + 1;
      else if (nums2LeftEnd > nums1RightStart)
        j = mid - 1;
    }
  }

private:
  int indexTwoArrays(std::vector<int> &nums1, std::vector<int> &nums2,
                     int index) {
    if (index < nums1.size())
      return nums1[index];
    else
      return nums2[index - nums1.size()];
  }

  double medianTwoArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
    int total = nums1.size() + nums2.size();
    int half = total / 2;

    if (total % 2 == 0) {
      int sum = indexTwoArrays(nums1, nums2, half - 1) +
                indexTwoArrays(nums1, nums2, half);
      return ((double)sum) / 2.;
    } else
      return indexTwoArrays(nums1, nums2, half);
  }
};
