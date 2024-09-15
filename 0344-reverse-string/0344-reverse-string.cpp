class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty ())
            return;

        for (int left = 0, right = s.size () - 1; left <= right; left++, right--){
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        }
    }
};