class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> data; // nums -> freq
        for (int i = 0; i < nums.size (); i++) {
            data[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq; // freq -> nums
        for (auto &[val, freq] : data) {
            pq.push ({freq, val});
        }
        vector<int> res;
        while (!pq.empty () && k-- > 0) {
            res.push_back (pq.top ().second);
            pq.pop ();
        }
        return res;
    }
};