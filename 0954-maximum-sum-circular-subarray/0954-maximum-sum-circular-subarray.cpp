class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0;
        int maxsum = nums[0];
        int curmax = 0;
        int minsum = nums[0];
        int curmin = 0;
        for (int i = 0; i < nums.size (); i++) {
            curmax = max (curmax + nums[i], nums[i]);
            maxsum = max (maxsum, curmax);
            curmin = min (curmin + nums[i], nums[i]);
            minsum = min (minsum, curmin);
            total += nums[i];
        }
        return maxsum > 0 ? max (maxsum, total - minsum) : maxsum;
    }
};