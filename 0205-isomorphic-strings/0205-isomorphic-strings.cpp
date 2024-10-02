class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size () != t.size ())
            return false;
        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;
        for (int i = 0; i < s.size (); i++) {
            char s_letter = s[i];
            char t_letter = t[i];
            auto s_it = s_map.find (t_letter);
            auto t_it = t_map.find (s_letter);
            if (s_it == s_map.end () && t_it == t_map.end ()) {
                s_map[t_letter] = i;
                t_map[s_letter] = i;
            } else if (s_it != s_map.end () && t_it == t_map.end () || t_it != t_map.end () && s_it == s_map.end ()) {
                return false;
            } else if (s_it->second != t_it->second)
                return false;
        }
        return true;
    }
};