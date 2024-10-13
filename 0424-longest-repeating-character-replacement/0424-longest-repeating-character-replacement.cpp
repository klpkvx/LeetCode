class Solution {
public:

    int most_freq (unordered_map<char,int>  &win) {
        int mx = -1;
        for (auto &[elem, val] : win)
            mx =  max (mx, val);
        return mx;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> win; // s[i] -> freq
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < s.size (); right++) {
            win[s[right]]++;
            while (left < s.size () && right - left + 1 - most_freq (win) > k) {
                win[s[left]]--;
                if (win[s[left]] == 0)
                    win.erase (s[left]);
                left++;
            }
            max_len = max (max_len, right - left + 1);
        }
        return max_len;
    }
};