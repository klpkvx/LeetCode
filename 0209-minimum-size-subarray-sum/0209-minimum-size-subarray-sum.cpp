class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int sum = 0;
        int min_val = INT_MAX;
        for (int right = 0; right < nums.size (); right++) {
            sum += nums[right];
            while (sum >= target) {
                min_val = min (min_val, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return min_val == INT_MAX ? 0 : min_val;
    }
};