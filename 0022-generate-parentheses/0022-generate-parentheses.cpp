class Solution {
public:
    vector<string> answer;
    void solve (string &s, int open, int closed, int n) {
        if (open == closed && open + closed == 2 * n) {
            answer.push_back (s);
            return;
        }

        if (open < n) {
            s.push_back ('(');
            solve (s, open + 1, closed, n);
            s.pop_back ();
        }

        if (closed < open) {
            s.push_back (')');
            solve (s, open, closed + 1, n);
            s.pop_back ();
        }
    }

    vector<string> generateParenthesis(int n) {
        string s;
        solve (s, 0, 0, n);
        return answer;
    }
};