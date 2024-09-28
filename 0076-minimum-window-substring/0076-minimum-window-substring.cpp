class Solution {
public:
// string s including t in any order with duplicates
    string minWindow(string s, string t) {
        unordered_map<char, int> t_data; // t[i] -> count
        for (int i = 0; i < t.size (); i++) {
            t_data[t[i]]++;
        }
        int remain_chars = t.size ();
        vector<int> minw = {0, INT_MAX};
        for (int j = 0, i = 0; i < s.size (); i++) {
            char letter = s[i];
            if (t_data.find (letter) != t_data.end () && t_data[letter] > 0) {
                remain_chars--;
            }
            t_data[letter]--;
            if (remain_chars == 0) {
                // collapse window
                while (true) {
                    char lt = s[j];
                    if (t_data.find (lt) != t_data.end () && t_data[lt] == 0) {
                        break;
                    }
                    t_data[lt]++;
                    j++;
                }

                if (i - j < minw[1] - minw[0]) {
                    minw[0] = j;
                    minw[1] = i;
                }

                remain_chars++;
                t_data[s[j]]++;
                j++;
            }
        }
        if (minw[1] >= s.size ())
            return "";
        return s.substr (minw[0], minw[1] - minw[0] + 1);
    }
};