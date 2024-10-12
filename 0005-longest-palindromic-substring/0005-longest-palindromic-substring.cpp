class Solution {
public:
    string longestPalindrome(string s) {
            int left = 0;
            int right = s.size () - 1;
            string answer;
            int max_len = 0;
            for (int i = 0; i < s.size (); i++) {
                auto check_substr = [&] (int left, int right) -> void {
                    while (left >= 0 && right < s.size () && s[left] == s[right]) {
                            if (right - left + 1 > max_len) {
                                max_len = right - left + 1;
                                answer = s.substr (left, right - left + 1);
                            }
                        left--;
                        right++;
                    }
                };
                check_substr (i, i);
                check_substr (i, i + 1);
            }
            return answer;
    }
};