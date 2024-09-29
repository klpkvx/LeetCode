class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int word_len = 0;
        for (int i = s.size () - 1; i >= 0;) {
            while (i >= 0 && s[i] == ' ')
                i--;

            while (i >= 0 && s[i--] != ' '){
                len++;
                word_len = len;
            }
            if (word_len != 0)
                break;
        }
        return word_len;
    }
};