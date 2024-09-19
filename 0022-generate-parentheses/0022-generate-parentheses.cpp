class Solution {
public:
    void generate (vector<string> &answer, string &curr, int n, int open, int close) {
        if (curr.size () == n * 2) {
            answer.push_back (curr);
        }
        if (open < n) {
            curr.push_back ('(');
            generate (answer, curr, n, open + 1, close);
            curr.pop_back ();
        }

        if (close < open) {
            curr.push_back (')');
            generate (answer, curr, n, open, close + 1);
            curr.pop_back ();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> answer;
        string curr;
        generate (answer, curr, n, 0, 0);
        return answer;
    }
};