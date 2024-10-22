class Solution {
public:
    vector<string> answer;
    int count = {};
    void dfs (string &s, int open, int closed) {
        if (open + closed == count) {
            answer.push_back (s);
            return;
        }

        if (open < count / 2) {
            s.push_back ('(');
            dfs (s, open + 1, closed);
            s.pop_back ();
        }

        if (closed < open) {
            s.push_back (')');
            dfs (s, open, closed + 1);
            s.pop_back ();
        }
    }

    vector<string> generateParenthesis(int n) {
        string tmp;
        count = 2 * n;
        dfs (tmp, 0, 0);
        return answer;
    }
};