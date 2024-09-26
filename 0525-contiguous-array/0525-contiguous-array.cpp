class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> data = {{0, -1}}; // diff = non-zeroes - zeroes -> start_index;
        int non_zeroes = 0;
        int zeroes = 0;
        int ans = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] == 0) {
                zeroes++;
            } else {
                non_zeroes++;
            }
            int diff = non_zeroes - zeroes;
            if (data.contains (diff)) {
                ans = max (ans, i - data[diff]);
            } else 
                data[diff] = i;
        }
        return ans;
    }
};