class Solution {
    private List<String> out = new ArrayList<>();
    private String s = "";
    private int c = 0;
    private int n;
    
    private void backtrack() {
        if (s.length() == 2 * n) {
            if (c == 0) {
                out.add(new String(s));
            }
            return;
        }
        
        s += '(';
        c++;
        backtrack();

        s = s.substring(0, s.length() - 1);
        c--;

        if (c > 0) {
            s += ')';
            c--;
            backtrack();

            s = s.substring(0, s.length() - 1);
            c++;
        }
    }

    public List<String> generateParenthesis(int n) {
        this.n = n;
        backtrack();
        return out;
    }
}
