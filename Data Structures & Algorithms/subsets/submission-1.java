class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> out = new ArrayList<>();
        backtrack(0, nums, new ArrayList<Integer>(), out);
        return out;
    }

    public void backtrack(int i, int[] nums, List<Integer> sub, List<List<Integer>> out) {
        if (i >= nums.length) {
            out.add(new ArrayList<Integer>(sub));
            return;
        }

        sub.add(nums[i]);
        backtrack(i+1, nums, sub, out);

        sub.remove(sub.size() - 1);
        backtrack(i+1, nums, sub, out);
    }
}
