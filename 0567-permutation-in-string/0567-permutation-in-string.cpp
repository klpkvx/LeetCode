class Solution {
public:
    bool is_same (const unordered_map<char, int> &reference, const unordered_map<char, int> &tmp) {
        for (const auto &[letter, count] : reference) {
            auto it = tmp.find (letter);
            if (it == tmp.end ())
                return false;
            if (it->second != count)
                return false;
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int> reference;
        for (char c : s1) {
            reference[c]++;
        }
        int window_sz = s1.size ();
        int left = 0;
        unordered_map<char,int> tmp;
        for (int right = 0; right < s2.size (); right++) {
            tmp[s2[right]]++;
            while (left < s2.size () && right - left + 1 > window_sz) {
                tmp[s2[left]]--;
                left++;
            }
            if (right - left + 1 == window_sz && is_same (reference, tmp))
                return true;
        }
        return false;
    }
};