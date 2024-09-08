class Solution {
public:

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> data; // word -> count

        for (const auto &word : words)
            data[word]++;
        
        vector<pair<int, string>> tmp_result;
        for (const auto &[word, count] : data)
            tmp_result.emplace_back (count, word);

        sort (tmp_result.begin (), tmp_result.end (), [] (const pair<int, string> &left, const pair<int, string> &right) {
            if (left.first == right.first){
                return left.second < right.second;
            }
            return left.first > right.first;
        });

        vector<string> result;
        for (const auto &data : tmp_result){
            if (k > 0){
                result.emplace_back (data.second);
                k--;
            }
        }



        return result;
    }
};