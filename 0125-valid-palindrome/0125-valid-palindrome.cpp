class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size () - 1;

        while (left <= right){
            while (left < s.size () && !isalnum (s[left]))
                left++;
            while (right < s.size () && !isalnum (s[right]))
                right--;

            if (left > s.size () - 1 || right > s.size () - 1)
                return true;

            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;
            right--;
        }
        return true;
    }
};