class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> data = {{0, -1}}; // len diff -> index
        int ans = 0;
        int zeroes = 0, nonzeroes = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] == 0) 
                zeroes++;
            else 
                nonzeroes++;
            int diff = nonzeroes - zeroes;
            if (data.contains (diff)) {
                ans = max (ans, i - data[diff]);
            } else {
                data[diff] = i;
            }
        }
        return ans;
    }
};