class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty () && t.empty ())
            return true;
            
        if (s.size () > t.size ())
            return false;

        int sptr = 0;
        for (int i = 0; i < t.size (); i++){
            if (sptr < s.size () && t[i] == s[sptr]){
                sptr++;
            }
            if (sptr == s.size ())
                return true;
        }
        return false;
    }
};