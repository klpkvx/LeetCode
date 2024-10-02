class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> r_data;
        for (char c : magazine) {
            r_data[c]++;
        }

        for (char c : ransomNote) {
            if (r_data[c] == 0) {
                return false;
            }
            r_data[c]--;
        }
        return true;
    }
};