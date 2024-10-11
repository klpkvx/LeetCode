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
            
            while (end >= 0 && start < s.size () && (end + start) / 2 >= start ) {
                swap (s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};