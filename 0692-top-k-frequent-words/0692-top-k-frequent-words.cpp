class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> data; // word -> frequency
        for (const string &word : words) {
            data[word]++;
        }

        auto cmp = [] (const pair<int,string> &left, const pair<int, string> &right){
            if (left.first == right.first) {
                return left.second > right.second;
            };
            return left.first < right.first;
        };

        priority_queue<pair<int, string>, vector<pair<int,string>>, decltype (cmp)> pq (cmp);
        for (const auto &[word, freq] : data) {
            pq.push ({freq, word});
        }

        vector<string> answer;
        while (!pq.empty ()) {
            auto  &elem = pq.top ();
            if (k-- > 0)
                answer.push_back (elem.second);
            else {
                break;
            }
            pq.pop ();
        }
        return answer;
    }
};