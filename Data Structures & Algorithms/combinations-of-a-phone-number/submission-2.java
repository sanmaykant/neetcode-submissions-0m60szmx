class Solution {
    private String digits = "";
    private StringBuilder s = new StringBuilder();
    private List<String> out = new ArrayList<>();
    private List<String> intToStr = Arrays.asList(
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    );

    public List<String> letterCombinations(String digits) {
        if (digits.length() == 0)
            return out; 
        this.digits = digits;
        backtrack(0);
        return out;
    }

    private void backtrack(int i) {
        if (digits.length() == i) {
            out.add(new String(s));
            return;
        }

        String str = intToStr.get(digits.charAt(i) - '0');
        for (char c : str.toCharArray()) {
            s.append(c);
            backtrack(i + 1);
            s.deleteCharAt(s.length() - 1);
        }
    }
}
