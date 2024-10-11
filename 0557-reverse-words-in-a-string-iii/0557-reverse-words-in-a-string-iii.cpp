class Solution {
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size ();) {
            while (i < s.size () && s[i] == ' ')
                i++;
            int start = i;
            int end = start;
            while (i < s.size () && s[i] != ' ') {
                end = i;
                i++;
            }
            
            while ((end + start) >= start * 2) {
                swap (s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};