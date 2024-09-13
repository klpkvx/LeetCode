class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> data; // char -> freq;
        int result = 0;
        int left = 0;
        int right = 0;
        int maxf = 0;
        for (int right = 0; right < s.size (); right++){
            data[s[right]]++;
            maxf = max (maxf, data[s[right]]);
            while (right - left + 1 - maxf > k){
                data[s[left]]--;
                left++;
            }

            result = max (result, right - left + 1);
        }
        return result;
    }
};