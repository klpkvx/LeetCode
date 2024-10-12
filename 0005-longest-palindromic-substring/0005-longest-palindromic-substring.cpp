class Solution {
public:
    string longestPalindrome(string s) {
            string answer;
            int max_len = 0;
            for (int i = 0; i < s.size (); i++) {
                auto solve = [&] (int left, int right) {
                    while (left >= 0 && right < s.size () && s[left] == s[right]) {
                        if (right - left + 1 > max_len) {
                            max_len = right - left + 1;
                            answer = s.substr (left, right - left + 1);
                        }
                        left--;
                        right++;
                    }
                };
                solve (i, i);
                solve (i, i + 1);
            }
            return answer;
    }
};