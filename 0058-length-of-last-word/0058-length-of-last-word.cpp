class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int word_len = 0;
        for (int i = 0; i < s.size ();) {
            while (i < s.size () && s[i] == ' ')
                i++;
            len = 0;    
            while (i < s.size () && s[i++] != ' '){
                len++;
                word_len = len;
            }
        }
        return word_len;
    }
};