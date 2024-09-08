class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> data; // nums[i] -> frequency

        for (auto elem : nums){
            data[elem]++;
        }

        priority_queue<pair<int, int>> pq;
        for (auto &[elem, freq] : data)
            pq.push ({freq, elem});

        vector<int> result;
        while (!pq.empty () && k > 0){
            result.push_back (pq.top ().second);
            k--;
            pq.pop ();
        }

        return result;
    }
};