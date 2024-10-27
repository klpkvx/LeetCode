class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix = {{0, -1}}; // prefsum -> index
        int sum = 0;
        for (int i = 0; i < nums.size (); i++) {
            sum += nums[i];
            int r = sum % k;
            if (prefix.contains (r)) {
                if (i - prefix[r] > 1)
                    return true;
            }
            prefix.insert ({r, i});
        }
        return false;
    }
};