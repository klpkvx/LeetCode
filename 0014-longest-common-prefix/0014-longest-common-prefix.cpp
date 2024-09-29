class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string max_pref = strs[0];
        for (int i = 1; i < strs.size (); i++) {
            string &curr_str = strs[i];
            curr_str.resize (min (curr_str.size (), max_pref.size ()));
            for (int j = 0; j < max_pref.size (); j++) {
                if (curr_str[j] != max_pref[j]) {
                    max_pref = max_pref.substr (0, j);
                    break;
                }
            }
        }
        return max_pref;   
    }
};