class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> q; // nums[i] -> i
        for (int i = 0; i < nums.size (); i++){
            q.push ({nums[i], i});
        }
        vector<pair<int,int>> res;
        while (!q.empty () && k--){
            const auto &elem = q.top ();
            res.push_back ({elem.first, elem.second});
            q.pop ();
        }
        sort (res.begin (), res.end (), [] (const pair<int,int> &a, const pair<int,int> &b){
            return a.second < b.second;
        });
        vector<int> result;
        for (auto &elem : res){
            result.push_back (elem.first);
        }
        return result;
    }
};