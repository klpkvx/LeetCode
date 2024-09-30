class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> t_data;
        int remain_chars = t.size ();
        for (int i = 0; i < t.size (); i++) {
            t_data[t[i]]++;
        }

        string answer;
        int left = 0;
        int min_value = INT_MAX;
        vector<int> minw = {0, INT_MAX};
        for (int right = 0; right < s.size (); right ++) {
            char letter = s[right];
            if (t_data.contains (letter) && t_data[letter] > 0) {
                remain_chars--;
            }
            t_data[letter]--;
            if (remain_chars == 0) {
                // squash window
                while (true) {
                    char lt = s[left];
                    if (t_data.contains (lt) && t_data[lt] == 0)
                        break;
                    t_data[lt]++;
                    left++;
                }

                if (right - left + 1 < minw[1] - minw[0]) {
                    minw[1] = right;
                    minw[0] = left;
                }
                remain_chars++;
                t_data[s[left]]++;
                left++;
            }
        }
        return minw[1] == INT_MAX ? "" : s.substr (minw[0], minw[1] - minw[0] + 1);
    }
};