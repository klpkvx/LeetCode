class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> data; // s[i] -> freq
        int left = 0, mx = INT_MIN;
        for (int right = 0; right < s.size (); right++) {
            data[s[right]]++;
            while (left < right && data[s[right]] > 1) {
                char letter = s[left];
                data[letter]--;
                if (data[letter] <= 0)
                    data.erase (letter);
                left++;
            }
            mx = max (mx, right - left + 1);
        }
        return mx == INT_MIN ? 0 : mx;
    }
};