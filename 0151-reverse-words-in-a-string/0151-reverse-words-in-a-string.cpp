class Solution {
public:
    string reverseWords(string s) {
        string answer;
        for (int i = s.size () - 1; i >= 0; i--) {
            string tmp_word;
            while (i >= 0 && s[i] != ' ')
                tmp_word.push_back (s[i--]);

            if (!tmp_word.empty ()) {
                reverse (tmp_word.begin (), tmp_word.end ());
                answer += move (answer.empty () ? tmp_word : " " + tmp_word);
            }            
        }
        return answer;
    }
};