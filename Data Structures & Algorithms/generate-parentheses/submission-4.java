class Solution {
    private List<String> out = new ArrayList<>();
    private StringBuilder s = new StringBuilder("");
    private int c = 0;
    private int n;

    private void backtrack() {
        if (s.length() == 2 * n) {
            if (c == 0) {
                out.add(s.toString());
            }
            return;
        }

        s.append("(");
        c++;
        backtrack();

        s.deleteCharAt(s.length() - 1);
        c--;

        if (c > 0) {
            s.append(")");
            c--;
            backtrack();

            s.deleteCharAt(s.length() - 1);
            c++;
        }
    }

    public List<String> generateParenthesis(int n) {
        this.n = n;
        backtrack();
        return out;
    }
}
