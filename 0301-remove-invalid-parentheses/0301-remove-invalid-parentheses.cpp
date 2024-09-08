class Solution {
public:

    void dfs (string &s, int index, int left_removed, int right_removed, int pair, string &path, unordered_set<string> &result)
    {
        if (index >= s.size ()){
            if (left_removed == 0 && right_removed == 0 && pair == 0)
                result.insert (path);
        }
        else{
            if (s[index] == '('){
                if (left_removed > 0)
                    dfs (s, index + 1, left_removed - 1, right_removed, pair, path, result);
                path.push_back (s[index]);
                dfs (s, index + 1, left_removed, right_removed, pair + 1, path, result);
                path.pop_back ();
            }
            else if (s[index] == ')'){
                if (right_removed > 0)
                    dfs (s, index + 1, left_removed, right_removed - 1, pair, path, result);
                if (pair > 0){
                    path.push_back (s[index]);
                    dfs (s, index + 1, left_removed, right_removed, pair - 1, path, result);
                    path.pop_back ();
                }
            }
            else{
                path.push_back (s[index]);
                dfs (s, index + 1, left_removed, right_removed, pair, path, result);
                path.pop_back ();
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> result;
        int left_removed = 0;
        int right_removed = 0;
        for (auto c : s){
            if (c == '('){
                left_removed++;
            }
            else if (c == ')'){
                if (left_removed != 0)
                    left_removed--;
                else
                    right_removed++;
            }
        }
        string data;
        dfs (s, 0, left_removed, right_removed, 0, data, result);
        return vector<string> (result.begin (), result.end ());
    }
};