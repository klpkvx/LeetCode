class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> data; // sym -> freq
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.size (); right++) {
            data[s[right]]++;
            while (left < s.size () && data[s[right]] > 1) {
                data[s[left]]--;
                left++;
            }
            max_len = max (max_len, right - left + 1);
        }
        return max_len;
    }
};