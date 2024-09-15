class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> s_arr (26, 0);
        vector<int> t_arr (26, 0);
        for (int i = 0; i < s.size (); i++){
            s_arr[s[i] - 'a']++;
        }
        for (int i = 0; i < t.size (); i++){
            t_arr[t[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++){
            if (s_arr[i] != t_arr[i])
                return false;
        }
        return true;
    }
};