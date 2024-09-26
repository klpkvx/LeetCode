class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> data = {{0, 1}}; // prefsum % k -> count
        int prefsum = 0;
        int count = 0;
        for (int i = 0; i < nums.size (); i++) {
            prefsum += nums[i];
            int r = prefsum % k;
            if (r < 0)
                r += k;
            if (data.contains (r)) {
                count += data[r];
                data[r]++;
            } else data[r] = 1;
        }
        return count;
    }
};