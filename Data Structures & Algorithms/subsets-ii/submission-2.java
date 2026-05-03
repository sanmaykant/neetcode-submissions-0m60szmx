class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> out = new ArrayList<>();
        List<Integer> sub = new ArrayList<>();
        
        backtrack(0, nums, sub, out);
        
        return out;
    }

    private void backtrack(int i, int[] nums, List<Integer> sub, List<List<Integer>> out) {
        if (i == nums.length) {
            out.add(new ArrayList<>(sub));
            return;
        }

        sub.add(nums[i]);
        backtrack(i + 1, nums, sub, out);

        sub.remove(sub.size() - 1);
        while (i + 1 < nums.length && nums[i] == nums[i + 1]) {
            i++;
        }
        backtrack(i + 1, nums, sub, out);
    }
}