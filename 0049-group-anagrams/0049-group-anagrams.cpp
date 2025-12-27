class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> mm;
        for (const std::string &str : strs)
        {
            std::string tmp_str = str;
            std::sort (tmp_str.begin (), tmp_str.end ());
            mm[tmp_str].push_back (str);
        }

        std::vector<std::vector<std::string>> res;
        for (const auto &[k, v] : mm)
            res.push_back (v);

        return res;
    }
};