class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> perms = new ArrayList<>();
        perms.add(new ArrayList<>());
        for (int num : nums) {
            List<List<Integer>> newPerms = new ArrayList<>();
            for (var l : perms) {
                for (int i = 0; i <= l.size(); i++) {
                    List<Integer> perm = new ArrayList<>(l);
                    perm.add(i, num);
                    newPerms.add(perm);
                }
            }
            perms.clear();
            perms = newPerms;
        }
        return perms;
    }
}
