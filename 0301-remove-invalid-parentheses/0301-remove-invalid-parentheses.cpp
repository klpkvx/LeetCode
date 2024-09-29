class Solution {
public:
    void solve (string &s, int index, int left_removed, int right_removed, int pairs, string &path,unordered_set<string> &answer){
        if (index == s.size ()) {
            if (left_removed == 0 && right_removed == 0 && pairs == 0) {
                answer.insert (path);
            }
            return;
        }

        char sym = s[index];
        if (sym != '(' && sym != ')') {
            path.push_back (sym);
            solve (s, index + 1, left_removed, right_removed, pairs, path, answer);
            path.pop_back ();
        }
        else {
            if (sym == '(') {
                if (left_removed > 0) {
                    solve (s, index + 1, left_removed - 1, right_removed, pairs, path, answer);
                }
                path.push_back (sym);
                solve (s, index + 1, left_removed, right_removed, pairs + 1, path, answer);
                path.pop_back ();
            }
            if (sym == ')') {
                if (right_removed > 0) {
                    solve (s, index + 1, left_removed, right_removed - 1, pairs, path, answer);
                }
                if (pairs > 0) {
                    path.push_back (sym);
                    solve (s, index + 1, left_removed, right_removed, pairs - 1, path, answer);
                    path.pop_back ();
                }
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> answer;
        int left_removed = 0;
        int right_removed = 0;
        for (auto c : s) {
            if (c == '(')
                left_removed++;
            if (c == ')') {
                if (left_removed != 0)
                    left_removed--;
                else
                    right_removed++;
            }
        }
        string path;
        solve (s, 0, left_removed, right_removed, 0, path, answer);
        return vector<string> (answer.begin (), answer.end ());
    }
};