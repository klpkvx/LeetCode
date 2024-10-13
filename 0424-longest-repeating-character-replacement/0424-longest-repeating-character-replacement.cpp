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
        int max_count = INT_MIN;
        for (int right = 0; right < s.size (); right++) {
            win[s[right]]++;
            max_count = max (max_count, win[s[right]]);
            while (left < s.size () && right - left + 1 - max_count > k) {
                win[s[left]]--;
                max_count = max (max_count, win[s[left]]);
                if (win[s[left]] == 0)
                    win.erase (s[left]);
                left++;
            }
            max_len = max (max_len, right - left + 1);
        }
        return max_len;
    }
};