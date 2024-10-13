class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> data; // nums[i] -> freq
        for (int i = 0; i < nums.size (); i++) {
            data[nums[i]]++;
        }
        auto cmp = [] (const pair<int, int> &left, const pair<int,int> &right) {
            return left.first < right.first;
        };
        // max_heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype (cmp)> pq (cmp); // freq -> nums[i]
        for (auto it = data.begin (); it != data.end (); ++it) {
            pq.push ({it->second, it->first});
        }
        vector<int> answer;
        while (k-- && !pq.empty ()) {
            answer.push_back (pq.top ().second);
            pq.pop ();
        }
        return answer;
    }
};