class Solution {
public:

    void reverse_word (string &s, int start, int end){
        while (start <= (end + start) / 2){
            swap (s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.size (); j++){
            if (s[j] == ' '){
                reverse_word (s, i, j - 1);
                i = j + 1;
            }
        }

        reverse_word (s, i, s.size () - 1);
        return s;
    }
};