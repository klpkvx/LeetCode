class Solution {
public:
    string reverseWords(string s) {
        string result;
        for (int i = s.size () - 1; i >= 0; i--) {
            string tmp;
            while (i >= 0 && s[i] != ' ') {
                tmp += s[i--];
            }
            if (!tmp.empty ()) {
                if (result.empty ())
                    result = tmp;
                else {
                    result = tmp + " " + result;
                }
            }
        }
        return result;
    }
};