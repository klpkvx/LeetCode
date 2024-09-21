class Solution {
public:

/*



*/
    int get_max_freq (unordered_map<char,int> &data) {
        int mx_freq = 0;
        for (auto &[sym, val] : data) {
            mx_freq = max (mx_freq, val);
        }
        return mx_freq;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> data; // symbol -> frequency in substring
        int left = 0;
        int right = 0;
        int max_len = 0;
        int max_freq = 0;
// AAAA: A(1), mx1, A(2), 
        for (int right = 0; right < s.size (); right++) {
            data[s[right]]++;
            max_freq = max (max_freq, data[s[right]]);
            while (left < s.size () && (right - left + 1) - max_freq > k) {
                data[s[left++]]--;
            }

            max_len = max (max_len, right - left + 1);
        }
        return max_len;
    }
};