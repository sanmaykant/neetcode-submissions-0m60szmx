class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);

        List<List<Integer>> out = new ArrayList<>();
        List<Integer> sub = new ArrayList<>();

        class Helper {
            void backtrack(int i) {
                if (i == nums.length) {
                    out.add(new ArrayList<>(sub));
                    return;
                }
                
                sub.add(nums[i]);
                backtrack(i+1);

                sub.remove(sub.size() - 1);
                while (i+1 < nums.length && nums[i] == nums[i+1]) {
                    i++;
                }
                backtrack(i+1);
            }
        };

        new Helper().backtrack(0);
        return out;
    }
}
