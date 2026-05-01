class Solution {
    private List<Integer> nums = new ArrayList<>();
    private HashMap<Integer, Integer> freqs = new HashMap<>();
    private List<List<Integer>> out = new ArrayList<>();
    
    private List<Integer> sub = new ArrayList<>();
    private int sum = 0;
    private int target;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        this.target = target;

        for (int num : candidates) {
            freqs.putIfAbsent(num, 0);
            freqs.put(num, freqs.get(num) + 1);
        }

        for (int num : freqs.keySet()) {
            nums.add(num);
        }
        Collections.sort(nums, Collections.reverseOrder());

        backtrack(0);

        return out;
    }

    private void backtrack(int i) {
        if (sum == target) {
            out.add(new ArrayList<Integer>(sub));
            return;
        }
        if (i >= nums.size() || sum > target) {
            return;
        }
        
        int num = nums.get(i);
        if (freqs.get(num) > 0) {
            sub.add(num);
            sum += num;
            freqs.put(num, freqs.get(num) - 1);
            
            backtrack(i);

            sub.remove(sub.size() - 1);
            sum -= num;
            freqs.put(num, freqs.get(num) + 1);
        }

        backtrack(i + 1);
    }
}
