class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> data = {{0, -1}}; // sum -> len
        int zeroes = 0, ones = 0;
        int max_len = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] == 0) zeroes++;
            else ones++;
            int diff = ones - zeroes;
            if (data.count (diff)) {
                max_len = max (max_len, i - data[diff]);
            } else data[diff] = i;           
        }
        return max_len;
    }
};