class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long max_sum = INT_MIN;
        long long tmp = 0;
        for (int i = 0; i < nums.size (); i++) {
            tmp += nums[i];
            if (tmp > max_sum) {
                max_sum = tmp;
            }
            if (tmp <= 0) {
                tmp = 0;
            }
        }
        return max_sum;
    }
};