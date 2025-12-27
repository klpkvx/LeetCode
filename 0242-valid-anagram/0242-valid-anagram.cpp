class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size () != t.size ())
          return false;

        std::unordered_map<char, int> mm;
        for (const char l : s)
            mm[l]++;
        for (const char t : t)
           mm[t]--;
        for (const auto &[k, v] : mm)
            if (v != 0)
                return false;

        return true;
    }
};