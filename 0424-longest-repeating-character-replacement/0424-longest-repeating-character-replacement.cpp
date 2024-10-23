class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freqs; // letter -> count
        int left = 0;
        int mx = 0;
        int mx_freq = 0;
        for (int right = 0; right < s.size (); right++) {
            freqs[s[right]]++;
            mx_freq = max (mx_freq, freqs[s[right]]);
            while (left < s.size () && right - left + 1  - mx_freq > k) {
                mx_freq = max (mx_freq, freqs[s[left]]);                
                freqs[s[left]]--;
                if (freqs[s[left]] == 0)
                    freqs.erase (s[left]);
                left++;
            }
            mx = max (mx, right - left + 1);
        }
        return mx;
    }
};