class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty () && t.empty ())
            return true;
        if (s.size () > t.size ())
            return false;
        int s_ptr = 0;
        for (int i = 0; i < t.size (); i++){
            if (t[i] == s[s_ptr]){
                s_ptr++;
            }
            if (s_ptr == s.size ())
                return true;
        }
        return false;
    }
};