class Solution {
public:
// string s including t in any order with duplicates
    string minWindow(string s, string t) {
        unordered_map<char, int> t_data; // t[i] -> count
        for (int i = 0; i < t.size (); i++) {
            t_data[t[i]]++;
        }
        int remain_chars = t.size ();
        vector<int> minW = {0, INT_MAX};
        for (int left = 0, right = 0; right < s.size (); right++) {
            char letter = s[right];
            if (t_data.find (letter) != t_data.end () && t_data[letter] > 0) {
                remain_chars--;
            }
            t_data[letter]--;
            if (remain_chars == 0) {
                while (left < s.size ()) {
                    char ch = s[left];
                    if (t_data.find (ch) != t_data.end () && t_data[ch] == 0) {
                        break;
                    }
                    t_data[ch]++;
                    left++;
                }

                if (right - left < minW[1] - minW[0]) {
                    minW[0] = left;
                    minW[1] = right;
                }

                remain_chars++;
                t_data[s[left]]++;
                left++;
            }
        }
        return minW[1] >= s.size () ? "" : s.substr (minW[0], minW[1] - minW[0] + 1);
    }
};