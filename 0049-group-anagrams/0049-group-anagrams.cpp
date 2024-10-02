class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> data;
        for (int i = 0; i < strs.size (); i++) {
            string sorted_word = strs[i];
            sort (sorted_word.begin (), sorted_word.end ());
            data[sorted_word].emplace_back (strs[i]);
        }
        vector<vector<string>> ans;
        for (const auto &[val, v] : data) {
            ans.emplace_back (v);
        }
        return ans;
    }
};