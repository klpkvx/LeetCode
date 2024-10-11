class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (t.size () != s.size ())
            return false;
        unordered_map<char, int> s_data; // s[i] -> index
        unordered_map<char, int> t_data; // s[i] -> index
        int sz = s.size ();
        for (int i = 0 ; i < sz; i++) {
            char s_letter = s[i];
            char t_letter = t[i];
            auto s_it = s_data.find (s_letter);
            auto t_it = t_data.find (t_letter);
            if (s_it == s_data.end () && t_it == t_data.end ()) {
                t_data[t_letter] = i;
                s_data[s_letter] = i;
            } else if (s_it != s_data.end () && t_it != t_data.end ()) {
                if (s_it->second != t_it->second)
                    return false;
            } else
                return false;
        }
        return true;
    }
};