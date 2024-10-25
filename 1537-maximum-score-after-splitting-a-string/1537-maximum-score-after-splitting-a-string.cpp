class Solution {
public:
    int maxScore(string s) {
        int ones = 0;
        int sz = s.size ();
        vector<int> ones_pref (sz + 1, 0);
        for (int i = 0; i < sz; i++) {
            // ones_pref[i + 1] = ones_pref[i] + (s[i] == '1' ? 1 : 0);
            if (s[i] == '1')
                ones++;
        }
        int zeroes = 0;
        int answer = 0;
        for (int i = 0; i < sz - 1; i++) {
            if (s[i] == '0') {
                zeroes++;
            } else {
                ones--;
            }
            answer = max (answer, zeroes + ones);
        }
        return answer;
    }
};