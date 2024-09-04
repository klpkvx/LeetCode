class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> data;
        for (int i = 0; i < strs.size (); i++)
        {
            string str = strs[i];
            sort (str.begin (), str.end ());
            data[str].push_back (strs[i]);
        }

        vector<string> tmp_res;
        for (auto &[key, val] : data)
            ans.push_back (val);
        return ans;
    }
};