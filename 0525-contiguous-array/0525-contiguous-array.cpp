class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> data = {{0, -1}}; // sum -> len
        int zero_count = 0;
        int one_count = 0;
        int max_len = 0;
        for (int i = 0; i < nums.size (); i++) {
            if (nums[i] == 0) {
                zero_count++;
            } else {
                one_count++;
            }
            int diff = one_count - zero_count;
            
            if (data.count (diff)) {
                max_len = max (max_len, i - data[diff]);
            }
            else data[diff] = i;
        }
        return max_len;
    }
};