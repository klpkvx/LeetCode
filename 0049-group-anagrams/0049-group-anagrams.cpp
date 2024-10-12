class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> s_data; // sorted ->  {strings}
        for (const string &s : strs) {
            string tmp = s;
            sort (tmp.begin (), tmp.end ());
            s_data[tmp].push_back (s);
        }
        vector<vector<string>> answer;
        for (auto &tmp : s_data )
            answer.push_back (std::move (tmp.second));
        return answer;
    }
};