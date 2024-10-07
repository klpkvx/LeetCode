class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int currmax = nums[0];
        for (int i = 1; i < nums.size (); i++) {
            currmax = max (currmax + nums[i], nums[i]);
            maxsum = max (maxsum, currmax);
        }
        return maxsum;
    }
};