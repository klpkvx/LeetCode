class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> data = {{0, -1}}; // r -> index
        int total = 0;
        for (int i = 0; i < nums.size (); i++) {
            total += nums[i];
            int r = total % k;
            auto it = data.find (r);
            if (it == data.end ())
                data[r] = i;
            else if (i - it->second > 1)
                return true;
        }
        return false;
    }
};