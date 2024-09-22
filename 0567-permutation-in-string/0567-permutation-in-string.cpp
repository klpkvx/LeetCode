class Solution {
public:

    bool is_same (const unordered_map<char, int> &s1_data, const unordered_map<char, int> &s2_data) {
        for (auto &[key, value] : s1_data) {
            unordered_map<char,int>::const_iterator it = s2_data.find (key);
            if (it == s2_data.end ())
                return false;
            if (it->second != value)
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1_data;
        unordered_map<char, int> s2_data;
        for (char c : s1) {
            s1_data[c]++;
        }

        int left = 0;
        for (int right = 0; right < s2.size (); right++) {
            s2_data[s2[right]]++;
            while (left < s2.size () && right - left + 1 > s1.size ()) {
                s2_data[s2[left]]--;
                left++;
            }

            if (right - left + 1 == s1.size () && is_same (s1_data, s2_data))
                return true;

        }
        return false;
    }
};