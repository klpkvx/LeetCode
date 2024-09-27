class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> data; // char -> max_index
        for (int i = 0; i < s.size (); i++) {
            data[s[i]] = i;
        }
        vector<int> answer;
        int max_index = 0, last_index = 0;
        for (int i = 0; i < s.size (); i++) {
            max_index = max (max_index, data[s[i]]);
            if (i == max_index) {
                answer.push_back (max_index - last_index + 1);
                last_index = max_index + 1;
            }
        }
        return answer;
    }
};