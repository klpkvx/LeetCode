class Solution {
public:

    bool is_same (const unordered_map<char,int> &data, const unordered_map<char,int> &p_data) {
        for (auto &[key, val] : p_data) {
            auto it = data.find (key);
            if (it == data.end ())
                return false;
            if (it->second != val)
                return false;
        }
        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> data;
        unordered_map<char, int> p_data;
        for (char c : p){
            p_data[c]++;
        }
        vector<int> answer;
        int left = 0;
        for (int right = 0; right < s.size (); right++) {
            data[s[right]]++;
            while (left < s.size () && right - left + 1 > p.size ()) { 
                data[s[left]]--;
                left++;
            }
            if (right - left + 1 == p.size () && is_same (data, p_data))
                answer.push_back (left);
        }
        return answer;        
    }
};