class Solution {
public:

    string longestPalindrome(string s) {
        const int sz = s.size ();
        string result;
        int max_len = -1;
        for (int i = 0; i < sz; i++) {
            auto check_substr = [&] (int left, int right) {
                while (left >= 0 && right < sz && s[left] == s[right]) {
                    if ( right - left + 1 > max_len) {
                        max_len = right - left + 1;
                        result = s.substr (left, right - left + 1);
                    }
                    left--;
                    right++;
                }
            };
            check_substr (i, i);
            check_substr (i, i + 1);
        }
        return result;
    }
};