class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window; // char -> freq
        int left = 0;
        int max_len = 0;
        for (int right = 0; right < s.size (); right++) {
            window[s[right]]++;
            while (left < s.size () && window[s[right]] > 1) {
                window[s[left]]--;
                if (window[s[left]] <= 0)
                    window.erase (s[left]);
                left++;
            }
            max_len = max (max_len, (int)window.size ());
        }
        return max_len;
    }
};