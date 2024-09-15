class Solution {
public:
    void reverse_word (string &s, int left, int right){
        while (left < right){
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    string reverseWords(string s) {
        int left = 0;
        int right = 0;
        while (right < s.size ()){
            while (right < s.size () && s[right] != ' ') right++;
            reverse_word (s, left, right - 1);
            right++;
            left = right;
        }
        return s;
    }
};