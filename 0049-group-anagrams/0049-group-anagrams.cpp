class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> data;
        for (const string &str : strs) {
            string tmp = str;
            sort (tmp.begin (), tmp.end ());
                data[tmp].push_back (str);
        }
        vector<vector<string>> ans;
        for (auto &[str, val] : data) {
            ans.push_back (std::move (val));
        }
        return ans;
    }
};