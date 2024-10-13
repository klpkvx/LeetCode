class Solution {
public:

    bool is_same (unordered_map<char,int> &p_data, unordered_map<char, int> &data) {
        for (auto &[elem, count] : p_data) {
            auto it = data.find (elem);
            if (it == data.end ())
                return false;
            if (it->second != count)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> answer;
        unordered_map<char, int> p_data; // p[i] -> freq
        for (int i = 0; i < p.size (); i++) {
            p_data[p[i]]++;
        }

        int left = 0;
        unordered_map<char,int> data;
        for (int right = 0; right < s.size (); right++) {
            data[s[right]]++;
            while (left < s.size () && right - left + 1 > p.size ()) {
                data[s[left]]--;
                left++;
            }

            if (right - left + 1 == p.size () && is_same (p_data, data)) {
                answer.push_back (left);
            }
        }
        return answer;
    }
};