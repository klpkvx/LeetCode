class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> data = {{0, -1}}; // value -> index
        int sum = 0;
        for (int i = 0; i < nums.size (); i++) {
            sum += nums[i];
            int total = sum % k;
            if (data.contains (total)) {
                if (i - data[total] > 1)
                    return true;
            } else {
                data[total] = i;
            }
        }
        return false;
    }
};