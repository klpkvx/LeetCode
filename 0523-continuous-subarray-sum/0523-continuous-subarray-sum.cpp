class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> data = {{0, -1}};
        int sum = 0;
        for (int i = 0; i < nums.size (); i++) {
            sum += nums[i];
            int q = sum % k;
            if (data.contains (q)) {
                if (i - data[q] > 1)
                    return true;
            }
            data.insert ({q, i});
        }
        return false;
    }
};