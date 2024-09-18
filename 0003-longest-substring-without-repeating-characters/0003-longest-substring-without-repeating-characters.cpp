class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty ())
            return 0;
        unordered_set<char> data;
        int left = 0;
        int right = 0;
        int size = s.size () - 1;
        int max_len = 0;
        while (right <= size) {
            while (right <= size && !data.contains (s[right])) {
                data.insert (s[right]);
                right++;
            }
            max_len = max (max_len, right - left);

            while (left <= size && right <= size && data.contains (s[right])) {
                data.erase (s[left]);
                left++;
            }
        }
        return max_len;
    }
};