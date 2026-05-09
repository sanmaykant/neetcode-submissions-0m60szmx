class Solution {
    public List<List<String>> partition(String s) {
        this.s = s;
        backtrack(0);
        return solution;
    }

    private void backtrack(int b) {
        if (b == (int) s.codePoints().count()) {
            solution.add(new ArrayList(candidate));
            return;
        }

        for (int e = b + 1; e <= (int) s.codePoints().count(); e++) {
            String substr = s.substring(b, e);
            if (!isPalindrome(substr))
                continue;
            candidate.add(substr);
            backtrack(e);
            candidate.remove(candidate.size() - 1);
        }
    }

    private boolean isPalindrome(String s) {
        int i = 0;
        int j = (int) s.codePoints().count() - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j))
                return false;
            i++;
            j--;
        }
        return true;
    }

    private String s;
    private List<String> candidate = new ArrayList<>();
    private List<List<String>> solution = new ArrayList<>();
}
