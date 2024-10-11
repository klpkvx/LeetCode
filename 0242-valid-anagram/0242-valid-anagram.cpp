class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> s_data; // s[i] -> freq;
        for (int i = 0; i < s.size (); i++) {
            s_data[s[i]]++;
        }
        for (int i = 0; i < t.size (); i++) {
            if (s_data.contains (t[i]) && s_data[t[i]] > 0) {
                s_data[t[i]]--;
            } else 
                return false;
        }
        return true && s.size () == t.size ();
    }
};