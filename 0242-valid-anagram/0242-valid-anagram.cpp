class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size () != t.size ())
            return false;
        unordered_map<char, int> s_data;
        for (char c : s)
            s_data[c]++;
        for (char c : t) {
            if (s_data[c] == 0)
                return false;
            s_data[c]--;
        }
        return true;
    }
};