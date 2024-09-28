class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,int>> merged_data; // [elem, index];
        vector<int> ans;
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size (); i++) {
            for (int j = 0; j < nums[i].size (); j++) {
                merged_data.push_back ({nums[i][j],i});
            }
        }

        sort (merged_data.begin (), merged_data.end ());
        int left = 0, cnt = 0;
        for (int right = 0; right < merged_data.size (); right++) {
            if (! count[merged_data[right].second]++)
                cnt++;
            if (cnt == nums.size ()) {
                while (count[merged_data[left].second] > 1) {
                    count[merged_data[left].second]--;
                    left++;
                }                    
                if (ans.empty () || ans[1] - ans[0] > merged_data[right].first - merged_data[left].first) {
                    ans = {merged_data[left].first, merged_data[right].first};
                }
            }
        }
        return ans;
    }
};