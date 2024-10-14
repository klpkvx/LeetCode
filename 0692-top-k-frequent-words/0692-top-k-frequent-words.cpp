class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> data; // word[i] -> frequency
        for (const string &word : words) {
            data[word]++;
        }

        auto cmp = [] (pair<string,int> &lhs, pair<string,int> &rhs) {
            if (lhs.second == rhs.second)
                return !(lhs.first < rhs.first);
            return lhs.second < rhs.second;
        };
        priority_queue<pair<string, int>, vector<pair<string,int>>, decltype (cmp)> pq (cmp);
        for (auto &[str, val] : data) {
            pq.push ({str, val});
        }

        vector<string> answer;
        while (!pq.empty () && k--) {
            answer.push_back (pq.top ().first);
            pq.pop ();
        }
        return answer;
    }
};