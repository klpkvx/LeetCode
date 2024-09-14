class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size () != t.size ())
            return false;

        unordered_map<char, char> map_s;
        unordered_map<char, char> map_t;
        for (int i = 0; i < s.size (); i++){
            char s_sym = s[i];
            char t_sym = t[i];
            auto it_s = map_s.find (s_sym);
            auto it_t = map_t.find (t_sym);
            if (it_s == map_s.end () && it_t == map_t.end ()){
                map_s[s_sym] = i;
                map_t[t_sym] = i;
            }
            else if (it_s == map_s.end () && it_t != map_t.end ())
                return false;
            else if (it_s != map_s.end () && it_t == map_t.end ())
                return false;
            else{
                if (it_s->second != it_t->second)
                    return false;
            }
        }
        return true;
    }
};