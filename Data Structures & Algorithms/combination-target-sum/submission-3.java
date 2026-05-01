class Solution {
    public List<List<Integer>> combinationSum(int[] nums, int target) {
        List<List<Integer>> out = new ArrayList<>();

        List<Integer> sub = new ArrayList<Integer>();

        class Helper {
            int sum = 0;

            void backtrack(int i) {
                if (sum == target) {
                    out.add(new ArrayList<Integer>(sub));
                }
                if (i >= nums.length || sum >= target) {
                    return;
                }

                sub.add(nums[i]);
                sum += nums[i];
                backtrack(i);

                sub.remove(sub.size() - 1);
                sum -= nums[i];
                backtrack(i+1);
            }
        };

        new Helper().backtrack(0);
        return out;
    }
}
